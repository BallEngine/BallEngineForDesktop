/*****************************************************************************
FileName:   Manager.h
Creater:    Xeler
Desc:       Define ManagerType,EventMessage and Manager class(Super virtual class of other Manager).
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_MANAGER_H
#define BALLENGINE4CPP_MANAGER_H

#include "define.h"
#include "../BaseType/BString.h"

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
        BEvent(ManagerType whereFrom, ManagerType wantTo, BString eventMessage);
        ManagerType from, to;
        BString data;
    };

    class Manager {
    public:
        Manager();
        virtual void processEvent(BEvent event);
    };

BE_END

#endif //BALLENGINE4CPP_MANAGER_H
