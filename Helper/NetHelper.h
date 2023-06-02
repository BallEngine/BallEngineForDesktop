/*****************************************************************************
FileName:   NetHelper.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE_NETHELPER_H
#define BALLENGINE_NETHELPER_H

#include <queue>
#include <string>

#include <unistd.h>

#ifdef LINUX


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif
#ifdef WIN32

#include <winsock2.h>
#include <windows.h>
#include <inaddr.h>
#include <pthread.h>

#pragma comment(lib, "ws2_32.lib")

#endif

namespace be {

    class NetHelper {
    public:
        explicit NetHelper();

        ~NetHelper();

        void init(unsigned int port = 21324, std::string ip = "0.0.0.0", bool isServer = true); //port:bmx

        void close();

        bool isRunning();

        bool sendMessage(const char *buffer, unsigned int size);

        bool sendMessage(std::string msg);

        unsigned int recvMessage(std::string &msg);

        unsigned int recvMessage(char *buffer, unsigned int size);

        NetHelper &operator>>(std::string &str);

        NetHelper &operator<<(std::string &str);

    private:
        bool m_isRunning;
        SOCKET m_connectSocket;
        sockaddr_in m_connectAddress;
        std::queue<std::string> m_messageQueue;
    };

}

#endif //BALLENGINE_NETHELPER_H
