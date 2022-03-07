/*****************************************************************************
FileName:   SystemInterface.h
Creater:    Xeler
Desc:       Interface's template,virtual super class.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_SYSTEMINTERFACE_H
#define BALLENGINE4CPP_SYSTEMINTERFACE_H

#include "define.h"
#include "Manager.h"

BE_BEGIN

    class SystemInterface {
    public:
        explicit SystemInterface();

        ~SystemInterface();

        BImage pretreatmentFrame(BImage frame);

        virtual void updateFrame(BImage);

        virtual void processEvent(BEvent event);
    };

BE_END

#endif //BALLENGINE4CPP_SYSTEMINTERFACE_H
