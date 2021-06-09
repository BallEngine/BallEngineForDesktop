/*****************************************************************************
FileName:   BallEngine.h
Creater:    Xeler
Date:       2021/04/20
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

_BE_BEGIN

    class Manager;

    class BallEngine {
    public:
        static BallEngine &getEngine();
        void emit(Event event);
    private:
        BallEngine();
        BallEngine(const BallEngine &engine);
        BallEngine &operator=(const BallEngine &engine);
    protected:
        //Engine Manager
        static BallEngine *ballEngine;
        AudioManager *audioManager;
        PasterManager *pasterManager;
        ScriptManager *scriptManager;
        //PlatformInterface
        SystemInterface *systemInterface;
    };

_BE_END

#endif //BALLENGINE4CPP_BALLENGINE_H
