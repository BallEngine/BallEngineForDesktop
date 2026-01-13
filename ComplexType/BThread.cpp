#include "BThread.h"

BE_USE

BThread::BThread(FuncType *func) {
    m_threadID = 0;
    m_ret = nullptr;
    m_status = 0;
    m_funcPtr = func;
}

BThread::~BThread() {
    if (m_threadID != 0) {
        pthread_cancel(m_threadID);
        pthread_join(m_threadID, nullptr);
    }
}

unsigned char BThread::getStatus() const {
    return m_status;
}

void *BThread::checkReturn() const {
    return m_ret;
}

void BThread::initThread(params arg) {
    if (!(m_status & 0x07)) {
        params *localArgs = new params;
        localArgs->size = arg.size;
        localArgs->buffer = static_cast<char *>(malloc(sizeof(char) * arg.size));
        if (localArgs->buffer != nullptr) {
            memcpy(localArgs->buffer, arg.buffer, arg.size);

            int result = pthread_create(&m_threadHandler, nullptr, m_funcPtr, localArgs);
            if (result == 0) {
                m_threadID = result;
                m_status |= BTHREAD_STATUS_WAITGO;
            } else {
                free(localArgs->buffer);
                delete localArgs;
                m_threadID = 0;
            }
        } else {
            delete localArgs;
        }
    }
}

void BThread::startThread() {
    if (m_status & BTHREAD_STATUS_WAITGO) {
        m_status |= BTHREAD_STATUS_RUNING;
        m_status &= ~BTHREAD_STATUS_WAITGO;
    }
}

void BThread::stopThread() {
    if (m_threadID != 0) {
        pthread_cancel(m_threadID);
        pthread_join(m_threadID, nullptr);
        m_threadID = 0;
        m_status &= ~BTHREAD_STATUS_RUNING;
    }
}

void BThread::pauseThread() {
    if (m_status & BTHREAD_STATUS_RUNING) {
        m_status |= BTHREAD_STATUS_HANGUP;
        m_status &= ~BTHREAD_STATUS_RUNING;
    }
}

void BThread::resumeThread() {
    if (m_status & BTHREAD_STATUS_HANGUP) {
        m_status |= BTHREAD_STATUS_RUNING;
        m_status &= ~BTHREAD_STATUS_HANGUP;
    }
}

void BThread::setArgs(void *args) {
    m_args = args;
}

bool BThread::isReady() {
    return m_status & BTHREAD_STATUS_WAITGO;
}

bool BThread::isRunning() {
    return m_status & BTHREAD_STATUS_RUNING;
}

bool BThread::isReturn() {
    return m_status & BTHREAD_STATUS_RETURN;
}

bool BThread::isHangup() {
    return m_status & BTHREAD_STATUS_HANGUP;
}
