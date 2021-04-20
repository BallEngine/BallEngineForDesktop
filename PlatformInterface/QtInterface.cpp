/*****************************************************************************
FileName:   QtInterface.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       QtInterface code.
Version:    0.1
******************************************************************************/

#include "QtInterface.h"

BallEngine *QtInterface::createEngine() {
    static QtBallEngine *qtBallEngine;
    return qtBallEngine;
}

void *QtInterface::castPasterToPic() {
    return nullptr;
}
