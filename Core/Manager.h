/*****************************************************************************
FileName:   Manager.h
Creater:    Xeler
Desc:       Define ManagerType,EventMessage and Manager class(Super virtual class of other Manager).
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_MANAGER_H
#define BALLENGINE4CPP_MANAGER_H

#include <string>

#include "define.h"

BE_BEGIN

    enum ManagerType {
        System = 0,
        Interface,
        PasterSys,
        ScriptSys,
        Other
    };

    class BEvent {
    public:
        BEvent(ManagerType whereFrom, ManagerType wantTo, std::string eventMessage);
        ManagerType from, to;
        std::string data;
    };

    class Manager {
    public:
        Manager();
        virtual void processEvent(BEvent event);
    };

BE_END

#endif //BALLENGINE4CPP_MANAGER_H
