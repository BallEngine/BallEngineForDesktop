/*****************************************************************************
FileName:   Manager.h
Creater:    Xeler
Date:       2021/04/20
Desc:       Define ManagerType,EventMessage and Manager class(Super virtual class of other Manager).
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_MANAGER_H
#define BALLENGINE4CPP_MANAGER_H

#include "../define.h"

_BE_BEGIN

    enum ManagerType {
        System = 0,
        Interface,
        PasterSys,
        ScriptSys,
        Other
    };

    class Event {
    public:
        Event(ManagerType whereFrom, ManagerType wantTo, BString eventMessage);
    protected:
        ManagerType from, to;
        BString data;
    };

    class Manager {
    public:
        Manager();
        Manager *retSelf();
        virtual void processEvent(Event event);
    };

_BE_END

#endif //BALLENGINE4CPP_MANAGER_H
