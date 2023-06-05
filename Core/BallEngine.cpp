/*****************************************************************************
FileName:   BallEngine.cpp
Author:     Xeler
Desc:       SDL window package class.
******************************************************************************/

#include "BallEngine.h"

BE_USE

BallEngine::BallEngine() {
    audioManager = new AudioManager();
    scriptManager = new ScriptManager();
    pasterManager = new PasterManager(width, height);
}

void BallEngine::init(const std::string &setupFile) {

    // Init
    SDL_Init(SDL_INIT_EVERYTHING);

    // Load Settings
    BConfig setup = BConfig(setupFile);

    SDL_CreateWindow("",);
}


void BallEngine::emitBEvent(const BEvent &event) {
    switch (event.to) {
        case AudioSys:
            audioManager->processEvent(event);
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

AudioManager &BallEngine::getAudioManager() {
    return *audioManager;
}

PasterManager &BallEngine::getPasterManager() {
    return *pasterManager;
}

ScriptManager &BallEngine::getScriptManager() {
    return *scriptManager;
}
