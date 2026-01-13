/*****************************************************************************
FileName:   BThread.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE_BTHREAD_H
#define BALLENGINE_BTHREAD_H

#ifdef LINUX

#include <unistd.h>

#endif
#ifdef WIN32

#define sleep Sleep

#include <windows.h>

#endif

#include <pthread.h>

typedef unsigned char uch;

#define BTHREAD_STATUS_WAITGO ((uch)1)
#define BTHREAD_STATUS_RUNING ((uch)2)
#define BTHREAD_STATUS_HANGUP ((uch)4)
#define BTHREAD_STATUS_RETURN ((uch)8)

#include "../Header/Define.h"

BE_BEGIN

    typedef void *FuncType(void *);

    typedef struct FuncArgs {
        unsigned long size;
        char *buffer;
    } params;

    class BThread {
    public:
        explicit BThread(FuncType *func);

        ~BThread();

        unsigned char getStatus() const;

        void *checkReturn() const;

        void initThread(params args);

        void startThread();

        void stopThread();

        void pauseThread();

        void resumeThread();

        void setArgs(void *args);

        bool isReady();

        bool isRunning();

        bool isReturn();

        bool isHangup();

    private:
        pthread_t m_threadHandler;
        unsigned int m_threadID;
        FuncType *m_funcPtr;
        unsigned short int m_status;
        void *m_args;
        void *m_ret;
    };

BE_END

#endif //BALLENGINE_BTHREAD_H
