/*****************************************************************************
FileName:   BallEngine.cpp
Author:     Xeler
Desc:       SDL window package class.
******************************************************************************/

#include "BallEngine.h"

BE_USE

BallEngine::BallEngine() : width(0), height(0) {
    audioManager = new AudioManager();
    scriptManager = new ScriptManager();
    pasterManager = new PasterManager();
}

void BallEngine::init(const std::string &setupFile) {
    SDL_Init(SDL_INIT_EVERYTHING);

    BConfig setup(setupFile);

    std::string title = setup.getValue("window.title");
    int width = std::stoi(setup.getValue("window.width"));
    int height = std::stoi(setup.getValue("window.height"));

    pasterManager->init(title.c_str(), width, height);
}


void BallEngine::emitBEvent(const BEvent &event) const {
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

AudioManager &BallEngine::getAudioManager() const {
    return *audioManager;
}

PasterManager &BallEngine::getPasterManager() const {
    return *pasterManager;
}

ScriptManager &BallEngine::getScriptManager() {
    return *scriptManager;
}
