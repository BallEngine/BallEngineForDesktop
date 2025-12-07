/*****************************************************************************
FileName:   Manager.cpp
Author:     Xeler
Desc:       Manager Code.
******************************************************************************/

#include "Manager.h"

BE_USE

BEvent::BEvent(ManagerType whereFrom, ManagerType wantTo, std::string eventMessage) {
    from = whereFrom;
    to = wantTo;
    data = eventMessage;
}

Manager::Manager() = default;

void Manager::processEvent(BEvent event) {

}
