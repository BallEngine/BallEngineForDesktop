/*****************************************************************************
FileName:   Manager.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Manager Code.
Version:    0.1
******************************************************************************/

#include "Manager.h"
#include "BallEngine.h"

_BE_USE

Event::Event(ManagerType whereFrom, ManagerType wantTo, BString eventMessage) {
    from = whereFrom;
    to = wantTo;
    data = eventMessage;
}

Manager::Manager() {
}

Manager *Manager::retSelf() {
    return this;
}
