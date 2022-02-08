/*****************************************************************************
FileName:   NetHelper.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_NETHELPER_H
#define BALLENGINE4CPP_NETHELPER_H

#include "../Other/BString.h"

#ifdef LINUX

#include <sys/socket.h>

#endif
#ifdef WIN32

#include <winsock2.h>
#include <windows.h>
#include <inaddr.h>
#include <pthread.h>

#endif

namespace be {

    class NetHelper {
    public:
        NetHelper(unsigned int port = 21324, BString ip = BString("0.0.0.0")); //port:bmx
        void serverStart();
        void clientStart();
        void close();
        bool isCrash();
        bool sendMessage(BString message);
        BString getMessage();
        BString operator>>(BString bString);
        NetHelper operator<<(BString bString);
        ~NetHelper();
    private:
        bool runtime;
        SOCKET connectSocket;
        sockaddr_in connectAddress;
    };

}

#endif //BALLENGINE4CPP_NETHELPER_H
