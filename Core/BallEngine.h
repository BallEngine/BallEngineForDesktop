/*****************************************************************************
FileName:   BallEngine.h
Creater:    Xeler
Desc:       Engine Head.
******************************************************************************/

#ifndef BALLENGINE4CPP_BALLENGINE_H
#define BALLENGINE4CPP_BALLENGINE_H

#include "define.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"
#include "../Manager/AudioManager.h"
#include "SystemInterface.h"
#include <thread>

BE_BEGIN

    class BallEngine {
    CLASS_OPTION:

        OPTION_SINGLETON_CLASS(BallEngine)

    CLASS_INTERFACE:

        INTERFACE_INSTANTIATION(BallEngine)

    public:

        void emitBEvent(const BEvent &event);

        void initialization(SystemInterface& interface);

        AudioManager &getAudioManager();

        PasterManager &getPasterManager();

        ScriptManager &getScriptManager();

        SystemInterface &getSystemInterface();

    protected:
        AudioManager *audioManager;
        PasterManager *pasterManager;
        ScriptManager *scriptManager;

        //PlatformInterface
        SystemInterface *systemInterface;
    };

BE_END

#endif //BALLENGINE4CPP_BALLENGINE_H
