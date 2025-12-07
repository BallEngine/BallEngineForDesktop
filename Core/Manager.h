/*****************************************************************************
FileName:   Manager.h
Author:     Xeler
Desc:       Define ManagerType,EventMessage and Manager class(Super virtual class of other Manager).
******************************************************************************/

#ifndef BALLENGINE_MANAGER_H
#define BALLENGINE_MANAGER_H

#include <string>

#include "../define.h"

BE_BEGIN
    enum ManagerType {
        AudioSys = 0,
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

        virtual ~Manager() = default;

        virtual void processEvent(BEvent event);
    };

BE_END

#endif //BALLENGINE_MANAGER_H
