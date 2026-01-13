/*****************************************************************************
FileName:   PasterManager.h
Author:     Xeler
Desc:       Define class Paster and PasterManager.
******************************************************************************/

#ifndef BALLENGINE_PASTERMANAGER_H
#define BALLENGINE_PASTERMANAGER_H

#include "../Header/Define.h"

#include <map>

#include "SDL2/SDL.h"

#include "../Core/Manager.h"
#include "../ComplexType/BPaster.h"

BE_BEGIN
    class PasterManager : public Manager {
    public:
        explicit PasterManager();

        ~PasterManager() override;

        void processEvent(BEvent event) override;

        PtrNum addPaster(const BPaster &paster);

        void removePaster(PtrNum point);

        bool setPaster(PtrNum point, const BPaster &paster);

        BPaster *operator[](PtrNum point);

        BPaster *getPaster(PtrNum point);

        void clear();

        SDL_Texture *drawScreen(unsigned short framesSpace = 1);

        void init(const char *title, int width, int height);

    private:
        SDL_Surface m_baseScreen;

        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        std::map<PtrNum, BPaster> m_pasterMap;
    };

BE_END

#endif //BALLENGINE_PASTERMANAGER_H
