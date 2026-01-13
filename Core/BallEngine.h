/*****************************************************************************
FileName:   BallEngine.h
Author:     Xeler
Desc:       Engine Head.
******************************************************************************/

#ifndef BALLENGINE_BALLENGINE_H
#define BALLENGINE_BALLENGINE_H

#include "../Header/Define.h"
#include "../Header/SingletonClassDefine.h"

#include <fstream>

#include "../ComplexType/BConfig.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"
#include "../Manager/AudioManager.h"

BE_USE

class BallEngine {
CLASS_OPTION:
    SINGLETON_CLASS(BallEngine)

public:
    void emitBEvent(const BEvent &event) const;

    void init(const std::string &setupFile = "./settings.ini");

    AudioManager &getAudioManager() const;

    PasterManager &getPasterManager() const;

    ScriptManager &getScriptManager();

protected:
    AudioManager *audioManager;
    PasterManager *pasterManager;
    ScriptManager *scriptManager;


    unsigned int width, height;
};

#endif //BALLENGINE_BALLENGINE_H
