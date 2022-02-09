/*****************************************************************************
FileName:   SystemInterface.h
Creater:    Xeler
Desc:       Interface's template,virtual super class.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_SYSTEMINTERFACE_H
#define BALLENGINE4CPP_SYSTEMINTERFACE_H

#include "../define.h"
#include "BallEngine.h"

BE_BEGIN

    class SystemInterface {
    public:
        virtual BallEngine *createEngine();
        virtual SystemInterface getInterface();
        virtual BImage updateFrame();
        virtual void *castPasterToPic();
        virtual void processEvent(Event event);
    protected:
        SystemInterface();
        virtual ~SystemInterface();
    };

BE_END

#endif //BALLENGINE4CPP_SYSTEMINTERFACE_H
