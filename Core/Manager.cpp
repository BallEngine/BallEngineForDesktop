/*****************************************************************************
FileName:   Manager.cpp
Creater:    Xeler
Desc:       Manager Code.
Version:    0.1
******************************************************************************/

#include "Manager.h"
#include "BallEngine.h"

BE_USE

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
