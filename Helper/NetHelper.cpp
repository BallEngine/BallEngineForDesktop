/*****************************************************************************
FileName:   NetHelper.cpp
Author:     Xeler
Desc:       Build.
******************************************************************************/


#include "NetHelper.h"

using namespace be;

NetHelper::NetHelper() {

}

NetHelper::~NetHelper() {

}

void NetHelper::init(unsigned int port, std::string ip, bool isServer) {
    m_connectSocket = socket(AF_INET, SOCK_DGRAM, 0);
    m_isRunning = false;
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

bool NetHelper::sendMessage(std::string msg) {
    unsigned long startIndex = 0;
    if (msg.length() <= 512) {
        sendto(connectSocket, message.c_str(), msg.length(), 0, (sockaddr *) (&connectAddress),
               sizeof(connectAddress));
    } else {
        while ((startIndex + 512) < msg.length()) {
            sendto(connectSocket, msg.substr(0, 512).c_str(), 512, 0,
                   (sockaddr *) (&connectAddress), sizeof(connectAddress));
            startIndex += 512;
        }
    }
    return true;
}

std::string NetHelper::getMessage(std::string msg) {
    return "";
}

NetHelper &NetHelper::operator>>(std::string &str) {
    getMessage(str);
    return *this;
}

NetHelper &NetHelper::operator<<(std::string &str) {
    sendMessage(str);
    return *this;
}
