/*****************************************************************************
FileName:   NetHelper.cpp
Creater:    Xeler
Desc:       Build.
******************************************************************************/


#include "NetHelper.h"

using namespace be;

NetHelper::NetHelper(unsigned int port, BString ip) {

    connectSocket = socket(AF_INET, SOCK_DGRAM, 0);
    runtime = true;
    memset(&connectAddress, 0, sizeof(sockaddr_in));
    connectAddress.sin_addr.S_un.S_addr = htonl(inet_addr(ip.toCStyleStr()));
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

bool NetHelper::sendMessage(BString message) {
    unsigned long startIndex = 0;
    if (message.getLength() <= 512) {
    } else {
        while ((startIndex + 512) < message.getLength()) {
            sendto(connectSocket, message.strSub(0, 512).toCStyleStr(), 512, 0,
                   (sockaddr *)(&connectAddress), sizeof(connectAddress));
            startIndex += 512;
        }
    }
    return true;
}

BString NetHelper::getMessage() {
    return BString();
}

BString NetHelper::operator>>(BString bString) {
    if (messageQueue.empty()) {
        return BString();
    } else {
        BString ret = BString(messageQueue.front());
        messageQueue.pop();
        return ret;
    }
}

NetHelper NetHelper::operator<<(BString bString) {
    return NetHelper();
}
