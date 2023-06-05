/*****************************************************************************
FileName:   PasterManager.h
Author:     Xeler
Desc:       Define class Paster and PasterManager.
******************************************************************************/

#ifndef BALLENGINE_PASTERMANAGER_H
#define BALLENGINE_PASTERMANAGER_H

#include "../define.h"

#include <map>
#include "SDL2/SDL.h"

#include "../Core/Manager.h"
#include "../ComplexType/BPaster.h"

BE_BEGIN

    class PasterManager : public Manager {
    public:
        explicit PasterManager(unsigned int width, unsigned int height);

        ~PasterManager();

        void processEvent(BEvent event) override;

        PtrNum addPaster(const BPaster &paster);

        bool removePaster(PtrNum point);

        BPaster &getPaster(PtrNum point);

        bool setPaster(PtrNum point, const BPaster &paster);

        bool checkPasterValid(PtrNum point);

        BPaster &operator[](PtrNum point);

        void clear();

        SDL_Surface drawScreen(unsigned short framesSpace = 1);

    private:
        SDL_Surface baseScreen;
        std::map<PtrNum, BPaster> pasterMap;
    };

BE_END

#endif //BALLENGINE_PASTERMANAGER_H
