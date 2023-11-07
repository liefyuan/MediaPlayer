#ifndef MP4RECORDER_H
#define MP4RECORDER_H

extern "C"
{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavfilter/avfilter.h"
    #include "libswscale/swscale.h"
    #include "libavutil/frame.h"
    #include "libavutil/imgutils.h"
}

#include <QObject>
#include <QMutex>

class mp4Recorder : public QObject
{
    Q_OBJECT
public:
    explicit mp4Recorder(QObject *parent = nullptr);
    virtual ~mp4Recorder();

    bool Init(AVFormatContext *pIfmtCtx, QString& sFile);
    bool DeInit();
    bool isInit() {return m_bInit;}
    bool saveOneFrame(AVPacket& pkt);

private:
    uint64_t         m_nCounts;
    bool             m_bFirstGoP;
    bool             m_bInit;
    QString          m_sRecordFile;
    AVFormatContext *m_pIfmtCtx;
    AVFormatContext *m_pOfmtCtx; // output stream format. copy from instream format.
    const AVOutputFormat  *m_pOfmt; // save file format.
    QMutex           m_lock;

    // stream map.
    int  *m_pStreamMapping;
    int   m_nMappingSize;

};

#endif // MP4RECORDER_H
