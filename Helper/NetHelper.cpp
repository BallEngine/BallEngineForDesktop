/*****************************************************************************
FileName:   NetHelper.cpp
Author:     Xeler
Desc:       Build.
******************************************************************************/


#include "NetHelper.h"

using namespace be;

NetHelper::NetHelper() {
    m_isRunning = false;
}

NetHelper::~NetHelper() {
    if (m_isRunning) {
        close();
    }
}

void NetHelper::init(unsigned int port, std::string ip, bool isServer) {
    m_connectSocket = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&m_connectAddress, 0, sizeof(sockaddr_in));
    m_connectAddress.sin_addr.S_un.S_addr = htonl(inet_addr(ip.c_str()));
    m_connectAddress.sin_port = htons(port);
    m_isRunning = bind(m_connectSocket, (sockaddr *) &m_connectAddress, sizeof(sockaddr_in));
    m_isRunning = m_isRunning && listen(m_connectSocket, SOMAXCONN);
}

void NetHelper::close() {
}

bool NetHelper::isRunning() {
    return m_isRunning;
}

bool NetHelper::sendMessage(const char *buffer, int size) {
    if (size <= 512) {
        sendto(m_connectSocket, buffer, size, 0, reinterpret_cast<sockaddr *>(&m_connectAddress),
               sizeof(m_connectAddress));
    } else {
        int startIndex = 0;
        while (startIndex < size) {
            int sendLength = (size - startIndex) > 512 ? 512 : (size - startIndex);
            sendto(m_connectSocket, buffer + startIndex, sendLength, 0,
                   reinterpret_cast<sockaddr *>(&m_connectAddress), sizeof(m_connectAddress));
            startIndex += sendLength;
        }
    }
    return m_isRunning;
}


bool NetHelper::sendMessage(const std::string &msg) {
    return sendMessage(msg.c_str(), msg.size());
}

unsigned int NetHelper::recvMessage(const std::string &msg) const {
    return recvMessage(msg.c_str(), static_cast<int>(msg.size()));
}

unsigned int NetHelper::recvMessage(const char *buffer, int size) const {
    unsigned int recvSize = 0;
    int startIndex = 0;

    while (startIndex < (int) size) {
        sockaddr_in fromAddr = {};
        int fromAddrLen = sizeof(fromAddr);
        int result = recvfrom(m_connectSocket, reinterpret_cast<char *>(buffer[startIndex]), size - startIndex, 0,
                              reinterpret_cast<sockaddr *>(&fromAddr), &fromAddrLen);
        if (result == SOCKET_ERROR) {
            return recvSize;
        }
        recvSize += result;
        startIndex += result;

        if (result < 512) {
            break;
        }
    }

    return recvSize;
}

NetHelper &NetHelper::operator>>(std::string &str) {
    recvMessage(str);
    return *this;
}

NetHelper &NetHelper::operator<<(const std::string &str) {
    sendMessage(str);
    return *this;
}
