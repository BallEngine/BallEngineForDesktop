/*****************************************************************************
FileName:   AudioManager.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BallEngine_AUDIOMANAGER_H
#define BallEngine_AUDIOMANAGER_H

#include "../Core/define.h"
#include "../Core/Manager.h"

BE_BEGIN

    class AudioManager : public Manager {
    public:
        AudioManager();

        void processEvent(BEvent event) override;
    };

BE_END

#endif //BallEngine_AUDIOMANAGER_H
