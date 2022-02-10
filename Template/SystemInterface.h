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

    virtual class SystemInterface {
    CLASS_OPTION:

        OPTION_SINGLETON_CLASS(SystemInterface);
    CLASS_INTERFACE:

        INTERFACE_INSTANTIATION(SystemInterface);
    public:

        ~SystemInterface() {};

        virtual BallEngine *createEngine() {};

        virtual SystemInterface getInterface() {};

        virtual BImage updateFrame() {};

        virtual void *castPasterToPic() {};

        virtual void processEvent(Event event) {};
    };

BE_END

#endif //BALLENGINE4CPP_SYSTEMINTERFACE_H
