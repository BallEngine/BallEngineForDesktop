/*****************************************************************************
FileName:   BallEngine.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Engine Code.
Version:    0.1
******************************************************************************/

#include "BallEngine.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"

_BE_USE

BallEngine *BallEngine::ballEngine = new BallEngine();

BallEngine::BallEngine() {
}

BallEngine &BallEngine::getEngine() {
    return *ballEngine;
}

void BallEngine::emit(Event event) {
    switch(event.to)    {
        case Interface:
            systemInterface->processEvent(event);
            break;
        case PasterSys:
            pasterManager->processEvent(event);
            break;
        case ScriptSys:
        case Other:
            scriptManager->processEvent(event);
            break;
        default:
            break;
    }
}
