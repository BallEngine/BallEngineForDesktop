/*****************************************************************************
FileName:   AudioManager.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE4CPP_AUDIOMANAGER_H
#define BALLENGINE4CPP_AUDIOMANAGER_H

#include "../Core/define.h"
#include "../Core/Manager.h"

BE_BEGIN

    class AudioManager : public Manager {
    public:
        AudioManager();

        void processEvent(BEvent event) override;
    };

BE_END

#endif //BALLENGINE4CPP_AUDIOMANAGER_H
