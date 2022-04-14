/*****************************************************************************
FileName:   NetHelper.h
Creater:    Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE4CPP_NETHELPER_H
#define BALLENGINE4CPP_NETHELPER_H

#include <queue>
#include "../BaseType/BString.h"

#ifdef LINUX

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif
#ifdef WIN32

#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <inaddr.h>
#include <pthread.h>

#pragma comment(lib, "ws2_32.lib")

#endif

namespace be {

    class NetHelper {
    public:
        explicit NetHelper(unsigned int port = 21324, BString ip = BString("0.0.0.0")); //port:bmx

        ~NetHelper();

        void serverStart();

        void clientStart();

        void close();

        bool isConnect();

        bool sendMessage(BString message);

        BString getMessage();

        BString operator>>(BString bString);

        NetHelper operator<<(BString bString);

    private:
        bool runtime;
        SOCKET connectSocket;
        sockaddr_in connectAddress;
        std::queue<BString> messageQueue;
    };

}

#endif //BALLENGINE4CPP_NETHELPER_H
