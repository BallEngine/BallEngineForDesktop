/*****************************************************************************
FileName:   NetHelper.cpp
Creater:    Xeler
Desc:       Build.
******************************************************************************/


#include "NetHelper.h"

using namespace be;

NetHelper::NetHelper(unsigned int port, std::string ip) {

    connectSocket = socket(AF_INET, SOCK_DGRAM, 0);
    runtime = true;
    memset(&connectAddress, 0, sizeof(sockaddr_in));
    connectAddress.sin_addr.S_un.S_addr = htonl(inet_addr(ip.c_str()));
    connectAddress.sin_port = htons(port);
    runtime = bind(connectSocket, (sockaddr *) &connectAddress, sizeof(sockaddr_in));
    runtime = runtime && listen(connectSocket, SOMAXCONN);
}

NetHelper::~NetHelper() {

}

void NetHelper::serverStart() {

}

void NetHelper::clientStart() {

}

void NetHelper::close() {

}

bool NetHelper::isConnect() {
    return connectSocket;
}

bool NetHelper::sendMessage(std::string message) {
    unsigned long startIndex = 0;
    if (message.length() <= 512) {
    } else {
        while ((startIndex + 512) < message.length()) {
            sendto(connectSocket, message.substr(0, 512).c_str(), 512, 0,
                   (sockaddr *) (&connectAddress), sizeof(connectAddress));
            startIndex += 512;
        }
    }
    return true;
}

std::string NetHelper::getMessage() {
    return "";
}

void NetHelper::operator>>(std::string &str) {
    if (messageQueue.empty()) {
        str = "";
    } else {
        str = messageQueue.front();
        messageQueue.pop();
    }
}

NetHelper &NetHelper::operator<<(std::string str) {
    sendMessage(str);
    return *this;
}
