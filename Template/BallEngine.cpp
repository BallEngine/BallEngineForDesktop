/*****************************************************************************
FileName:   BallEngine.cpp
Creater:    Xeler
Desc:       Engine Code.
Version:    0.1
******************************************************************************/

#include "BallEngine.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"

BE_USE

BallEngine *BallEngine::ballEngine = new BallEngine();

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
