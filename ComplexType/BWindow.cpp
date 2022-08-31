/*****************************************************************************
FileName:   BWindow.cpp
Author:     Xeler
Desc:       SDL window package class.
******************************************************************************/

#include "BWindow.h"

BE_USE

BWindow::BWindow(const std::string& title, int posX, int posY, int sizeX, int sizeY, Uint32 flag) {
    m_WindowPtr = SDL_CreateWindow(title.c_str(), posX, posY, sizeX, sizeY, flag);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    m_RendererPtr = SDL_CreateRenderer(m_WindowPtr, -1, SDL_RENDERER_ACCELERATED);
}

BWindow::~BWindow() {
    SDL_DestroyRenderer(m_RendererPtr);
    SDL_DestroyWindow(m_WindowPtr);
}
