/*****************************************************************************
FileName:   BThread.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "BThread.h"

using namespace be;

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

void BThread::startThread() {
    if (pthread_create(&threadID, nullptr, threadLoop, (void *) this)) {
    }
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
    args;
}

bool BThread::isReady() {

}

bool BThread::isRunning() {

}

bool BThread::isReturn() {

}

bool BThread::isHangup() {

}
