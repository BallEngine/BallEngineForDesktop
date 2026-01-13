/*****************************************************************************
FileName:   BAssets.h
Author:     Xeler
Desc:       Asset management class for loading and managing game resources.
******************************************************************************/
#ifndef BALLENGINE_BASSETS_H
#define BALLENGINE_BASSETS_H

#include "../Header/Define.h"
#include <map>
#include <string>
#include <SDL2/SDL.h>

BE_BEGIN

    class BAssets {
public:
    BAssets() = default;
    ~BAssets();

    SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
    SDL_Texture* getTexture(const std::string& id);
    bool releaseTexture(const std::string& id);

    void releaseAll();

private:
    std::map<std::string, SDL_Texture*> m_textures;
};

BE_END

#endif //BALLENGINE_BASSETS_H
