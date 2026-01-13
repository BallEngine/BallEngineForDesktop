/*****************************************************************************
FileName:   AudioManager.h
Author:     Xeler
Desc:       Desc
******************************************************************************/

#ifndef BALLENGINE_AUDIOMANAGER_H
#define BALLENGINE_AUDIOMANAGER_H

#include "../Header/Define.h"
#include "../Core/Manager.h"

BE_BEGIN

    class AudioManager : public Manager {
    public:
        AudioManager();

        void processEvent(BEvent event) override;
    };

BE_END

#endif //BALLENGINE_AUDIOMANAGER_H
