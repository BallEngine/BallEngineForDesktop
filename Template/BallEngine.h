/*****************************************************************************
FileName:   BallEngine.h
Creater:    Xeler
Desc:       Engine Head.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_BALLENGINE_H
#define BALLENGINE4CPP_BALLENGINE_H

#include "../define.h"
#include "../Manager/PasterManager.h"
#include "../Manager/ScriptManager.h"
#include "../Manager/AudioManager.h"
#include "SystemInterface.h"
#include <thread>

BE_BEGIN

    class Manager;

    class BallEngine {
    CLASS_OPTION:

        OPTION_SINGLETON_CLASS(BallEngine)
    CLASS_INTERFACE:

        INTERFACE_INSTANTIATION(BallEngine)

    public:

        void emit(Event event);

    protected:
        //Engine Manager
        static BallEngine *ballEngine;
        AudioManager *audioManager;
        PasterManager *pasterManager;
        ScriptManager *scriptManager;
        //PlatformInterface
        SystemInterface *systemInterface;
    };

BE_END

#endif //BALLENGINE4CPP_BALLENGINE_H
