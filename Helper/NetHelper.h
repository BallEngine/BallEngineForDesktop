/*****************************************************************************
FileName:   NetHelper.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE4CPP_NETHELPER_H
#define BALLENGINE4CPP_NETHELPER_H

#include <queue>
#include <string>

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
        explicit NetHelper(unsigned int port = 21324, std::string ip = "0.0.0.0"); //port:bmx

        ~NetHelper();

        void serverStart();

        void clientStart();

        void close();

        bool isConnect();

        bool sendMessage(std::string message);

        std::string getMessage();

        void operator>>(std::string &str);

        NetHelper &operator<<(std::string &str);

    private:
        bool runtime;
        SOCKET connectSocket;
        sockaddr_in connectAddress;
        std::queue<std::string> messageQueue;
    };

}

#endif //BALLENGINE4CPP_NETHELPER_H
