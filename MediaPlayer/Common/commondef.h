#ifndef COMMONDEFS_H
#define COMMONDEFS_H

#include <QObject>
#include <QDebug>
#include <QMetaType>


#define  MY_DEBUG  qDebug() << "[" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "] "
#define  ACT_ENABLE(act, en)  if(act) { act->setEnabled(en);}
#define  SAFE_FREE(p) \
do { \
    if(p) \
    { \
        delete p; \
        p = NULL; \
    } \
} while(0)

enum
{
  PROTOCOL_UDP = 0,
  PROTOCOL_TCP,
  PROTOCOL_HTTP
};

#define  SOFT_VERSION 1.0

#endif 
