#include "mp4recorder.h"
#include "commondef.h"

mp4Recorder::mp4Recorder(QObject *parent) : QObject(parent)
{
    QMutexLocker guard(&m_lock);
    m_sRecordFile.clear();
    m_pIfmtCtx = nullptr;
    m_pOfmtCtx = nullptr;
    m_pOfmt = nullptr;
    m_pStreamMapping = nullptr;
    m_nMappingSize = 0;
    m_nCounts = 0;
    m_bFirstGoP = false;
    m_bInit = false;
}

mp4Recorder::~mp4Recorder()
{
    DeInit();
}

bool mp4Recorder::Init(AVFormatContext *pIfmtCtx, QString &sFile)
{
    QMutexLocker guard(&m_lock);
    if(!pIfmtCtx || sFile.isEmpty())
    {
        MY_DEBUG << "sFile.isEmpty().";
        return false;
    }

    m_sRecordFile = sFile;
    m_pIfmtCtx = pIfmtCtx;

    QByteArray ba = m_sRecordFile.toLatin1();
    const char* pOutFile = ba.data();

    qDebug() << "pOutFile:" << pOutFile;

    unsigned i = 0;
    int ret = 0;
    int stream_index = 0;

    // 1. create output context
    avformat_alloc_output_context2(&m_pOfmtCtx, nullptr, nullptr, pOutFile);
    if (!m_pOfmtCtx)
    {
        MY_DEBUG << "Could not create output context.";
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    // 2. get memory.
    m_nMappingSize = pIfmtCtx->nb_streams;
    m_pStreamMapping = (int*)av_mallocz_array(m_nMappingSize, sizeof(*m_pStreamMapping));
    if (!m_pStreamMapping)
    {
        MY_DEBUG << "av_mallocz_array fail.";
        ret = AVERROR(ENOMEM);
        goto end;
    }

    // 3. copy steam information.
    m_pOfmt = m_pOfmtCtx->oformat;
    for (i = 0; i < pIfmtCtx->nb_streams; i++)
    {
        AVStream *pOutStream;
        AVStream *pInStream = pIfmtCtx->streams[i];
        AVCodecParameters *pInCodecpar = pInStream->codecpar;
        if (/*pInCodecpar->codec_type != AVMEDIA_TYPE_AUDIO &&*/
            pInCodecpar->codec_type != AVMEDIA_TYPE_VIDEO &&
            pInCodecpar->codec_type != AVMEDIA_TYPE_SUBTITLE)
        {
            m_pStreamMapping[i] = -1;
            continue;
        }
        // fill the stream index.
        m_pStreamMapping[i] = stream_index++;

        // copy the new codec prameters.
        pOutStream = avformat_new_stream(m_pOfmtCtx, nullptr);
        if (!pOutStream)
        {
            MY_DEBUG << "Failed allocating output stream";
            ret = AVERROR_UNKNOWN;
            goto end;
        }

        ret = avcodec_parameters_copy(pOutStream->codecpar, pInCodecpar);
        if (ret < 0)
        {
            MY_DEBUG << "Failed to copy codec parameters";
            goto end;
        }
        pOutStream->codecpar->codec_tag = 0;
    }

    // 4. create MP4 header.
    if (!(m_pOfmt->flags & AVFMT_NOFILE)) // network stream
    {
        ret = avio_open(&m_pOfmtCtx->pb, pOutFile, AVIO_FLAG_WRITE);
        if (ret < 0)
        {
            MY_DEBUG << "Could not open output file " << m_sRecordFile;
            goto end;
        }
    }
    // 5. write file header.
    ret = avformat_write_header(m_pOfmtCtx, nullptr);
    if (ret < 0)
    {
        MY_DEBUG << "Error occurred when opening output file ret:" << ret;
        goto end;
    }

    m_bFirstGoP = false;
    m_bInit = true;
    m_nCounts = 0;

    return true;

end:
    DeInit();
    if (ret < 0 && ret != AVERROR_EOF)
    {
        MY_DEBUG << "Error occurred.";
    }
    return false;
}

bool mp4Recorder::DeInit()
{
    // 1. save tail.
    if(m_bInit && m_pOfmtCtx)
    {
        av_write_trailer(m_pOfmtCtx);
    }
    m_bInit = false;

    // 2. close output
    if (m_pOfmtCtx && !(m_pOfmt->flags & AVFMT_NOFILE))
    {
        avio_closep(&m_pOfmtCtx->pb);
    }

    // 3. free contex.
    if(m_pOfmtCtx)
    {
        avformat_free_context(m_pOfmtCtx);
        m_pOfmtCtx = nullptr;
    }
    av_freep(&m_pStreamMapping);
    return true;
}

bool mp4Recorder::saveOneFrame(AVPacket &pkt)
{
    if(!m_bInit)
    {
        return false;
    }
    AVStream *pInStream, *pOutStream;

    if(m_bFirstGoP == false)
    {
        if(pkt.flags != AV_PKT_FLAG_KEY)
        {
            av_packet_unref(&pkt);
            return false; // first frame must be Iframe.
        }
        else
        {
            m_bFirstGoP = true;
        }
    }

    pInStream  = m_pIfmtCtx->streams[pkt.stream_index];
    if (pkt.stream_index >= m_nMappingSize ||
        m_pStreamMapping[pkt.stream_index] < 0)
    {
        av_packet_unref(&pkt);
        return true;
    }

    pkt.stream_index = m_pStreamMapping[pkt.stream_index];
    pOutStream = m_pOfmtCtx->streams[pkt.stream_index];

    av_packet_rescale_ts(&pkt, pInStream->time_base, pOutStream->time_base);
    pkt.pos = -1;

    int ret = av_interleaved_write_frame(m_pOfmtCtx, &pkt);
    av_packet_unref(&pkt);
    if (ret < 0)
    {
        qDebug() << "Error muxing packet";
    }

    return (ret == 0);
}
