/*****************************************************************************
FileName:   BallEngine.h
Author:     Xeler
Desc:       Engine Head.
******************************************************************************/

#ifndef BALLENGINE_BALLENGINE_H
#define BALLENGINE_BALLENGINE_H

#include "../define.h"

#include <fstream>

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

    void emitBEvent(const BEvent &event);

    void initialization(std::string setupFile = "./settings.ini");

    AudioManager &getAudioManager();

    PasterManager &getPasterManager();

    ScriptManager &getScriptManager();


protected:
    AudioManager *audioManager;
    PasterManager *pasterManager;
    ScriptManager *scriptManager;


};

#endif //BALLENGINE_BALLENGINE_H
