/*****************************************************************************
FileName:   BallEngine.h
Author:     Xeler
Desc:       Engine Head.
******************************************************************************/

#ifndef BALLENGINE_BALLENGINE_H
#define BALLENGINE_BALLENGINE_H

#include "../define.h"

#include <fstream>

#include "../ComplexType/BConfig.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"
#include "../Manager/AudioManager.h"

BE_USE

class BallEngine {
CLASS_OPTION:
    OPTION_SINGLETON_CLASS(BallEngine)

CLASS_INTERFACE:
    INTERFACE_INSTANTIATION(BallEngine)

public:
    void emitBEvent(const BEvent &event) const;

    void init(const std::string &setupFile = "./settings.ini");

    AudioManager &getAudioManager() const;

    PasterManager &getPasterManager() const;

    ScriptManager &getScriptManager() const;

protected:
    AudioManager *audioManager;
    PasterManager *pasterManager;
    ScriptManager *scriptManager;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    unsigned int width, height;
};

#endif //BALLENGINE_BALLENGINE_H
