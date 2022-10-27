/*****************************************************************************
FileName:   BWindow.cpp
Author:     Xeler
Desc:       SDL window package class.
******************************************************************************/

#ifndef BALLENGINE_BWINDOW_H
#define BALLENGINE_BWINDOW_H

#include <string>

#include <SDL2/SDL.h>

#include "../Core/define.h"

BE_BEGIN

    class BWindow {
    public:
        BWindow(const std::string& title, int posX, int posY, int sizeX, int sizeY, Uint32 flag);

        ~BWindow();

    protected:
        SDL_Window *m_WindowPtr;
        SDL_Renderer *m_RendererPtr;
    };

BE_END

#endif //BALLENGINE_BWINDOW_H
