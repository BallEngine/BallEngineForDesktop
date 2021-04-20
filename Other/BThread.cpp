/*****************************************************************************
FileName:   BThread.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "BThread.h"

using namespace be;

BThread::BThread(void *(*func)(int, char *[])) {
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
    status &= BTHREAD_NEW_RETURN_N;
    return ret;
}

void BThread::startThread() {
    status |= BTHREAD_RUN;
    if (pthread_create(&threadID, nullptr, threadLoop, (void *) this)) {
        status &= BTHREAD_RUN_N;
        status |= BTHREAD_ERROR_CANTCREATE;
    }
}

void BThread::stopThread() {
    status &= (BTHREAD_RUN_LOOP_N | BTHREAD_RUN_N | BTHREAD_ERROR_NUMBER_N);
    if (threadID == 0) {
        status |= BTHREAD_ERROR_CANTSTOP;
    } else {
        status |= BTHREAD_ERROR_STOP;
        pthread_kill(threadID, 9);
    }
}

void BThread::pauseThread() {
    status &= BTHREAD_RUN_LOOP_N;
}

void BThread::resumeThread() {
    status |= BTHREAD_RUN_LOOP;
}

bool BThread::isError() {
    return status & BTHREAD_ERROR_NUMBER;
}

void BThread::resetArg(int argc, char *argv[]) {
    args = {
            argc,
            argv
    };
}

void *threadLoop(void *threadPtr) {
    BThread *bThread = (BThread *) threadPtr;

    while (bThread->getStatus() & BTHREAD_RUN) {
        while (bThread->getStatus() & BTHREAD_NEW_RETURN) sleep(0);
        //TODO
        bThread->setStatus(bThread->getStatus());
    }
    return nullptr;
}
