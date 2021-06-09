/*****************************************************************************
FileName:   BThread.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_BTHREAD_H
#define BALLENGINE4CPP_BTHREAD_H

#ifdef LINUX

#include <unistd.h>

#endif
#ifdef WIN32

#define sleep Sleep
#include <windows.h>

#endif

#include <pthread.h>

typedef unsigned char uch;

/*
#define BTHREAD_STATUS_WAITGO   ((uch)1)
#define BTHREAD_STATUS_RUNING   ((uch)2)
#define BTHREAD_STATUS_RETURN   ((uch)4)
#define BTHREAD_STATUS_HANGUP   ((uch)8)
*/

namespace be {

    typedef void* FuncType(int, char *[]);

    class BThread {
    public:
        explicit BThread(FuncType *func);
        ~BThread();
        unsigned char getStatus();
        void *checkReturn();
        void startThread();
        void stopThread();
        void pauseThread();
        void resumeThread();
        void setArgs(void *args);
        //检测线程状态
        //是否准备执行
        bool isReady();
        //是否正在执行
        bool isRunning();
        //是否已返回
        bool isReturn();
        //是否挂起（暂停）
        bool isHangup();
    private:
        pthread_t threadID;
        FuncType *funcPtr;
        unsigned short int status;
        void *args;
        void *ret;
    };
}

#endif //BALLENGINE4CPP_BTHREAD_H
