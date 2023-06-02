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

bool NetHelper::sendMessage(const char *buffer, unsigned int size) {
    unsigned long startIndex = 0;
    if (size <= 512) {
        sendto(m_connectSocket, buffer, size, 0, (sockaddr *) (&m_connectAddress),
               sizeof(m_connectAddress));
    } else {
        while ((startIndex + 512) < size) {
            sendto(m_connectSocket, msg.substr(0, 512).c_str(), 512, 0,
                   (sockaddr *) (&m_connectAddress), sizeof(m_connectAddress));
            startIndex += 512;
        }
    }
    return m_isRunning;
}

bool NetHelper::sendMessage(std::string &msg) {
    return sendMessage(msg.c_str(), msg.size());
}

unsigned int NetHelper::recvMessage(char *buffer, unsigned int size) {
    unsigned int recvSize = 0;
    unsigned long startIndex = 0;
    if (size <= 512) {
        recvFrom(connectSocket, buffer, size);
    }
    return recvSize;
}

NetHelper &NetHelper::operator>>(std::string &str) {
    getMessage(str);
    return *this;
}

NetHelper &NetHelper::operator<<(std::string &str) {
    sendMessage(str);
    return *this;
}
