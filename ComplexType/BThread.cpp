/*****************************************************************************
FileName:   BThread.cpp
Author:     Xeler
Desc:       Desc
******************************************************************************/

#include "BThread.h"

BE_USE

BThread::BThread(FuncType *func) {
    threadID = 0;
    ret = nullptr;
    status = 0;
    funcPtr = func;
}

BThread::~BThread() {
    pthread_kill(threadID, 9);
}

unsigned char BThread::getStatus() {
    return status;
}

void *BThread::checkReturn() {
    return ret;
}

void BThread::initThread(params arg) {
    if (!(status | 0B0111)) {
        params localArgs;
        localArgs.size = arg.size;
        localArgs.buffer = (char *) malloc(sizeof(char) * arg.size);
        threadID = pthread_create(&threadHandler, nullptr, funcPtr, &localArgs);
        status ^= BTHREAD_STATUS_RETURN;
        status |= BTHREAD_STATUS_WAITGO;
    }
}

void BThread::startThread() {
    pthread_create(,);
}

void BThread::stopThread() {
    if (threadID == 0) {
    } else {
        pthread_kill(threadID, 9);
    }
}

void BThread::pauseThread() {
}

void BThread::resumeThread() {
}

void BThread::setArgs(void *args) {

}

bool BThread::isReady() {
    return status & BTHREAD_STATUS_WAITGO;
}

bool BThread::isRunning() {
    return status & BTHREAD_STATUS_RUNING;
}

bool BThread::isReturn() {
    return status & BTHREAD_STATUS_RETURN;
}

bool BThread::isHangup() {
    return status & BTHREAD_STATUS_HANGUP;
}
