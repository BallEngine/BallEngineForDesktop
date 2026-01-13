/*****************************************************************************
FileName:   BAssets.cpp
Author:     Xeler
Desc:       Asset management class implementation for loading and managing game resources.
******************************************************************************/
#include "BAssets.h"
#include <iostream>

BE_USE

BAssets::~BAssets() {
    releaseAll();
}

SDL_Texture *BAssets::loadTexture(const std::string &path, SDL_Renderer *renderer) {
    auto it = m_textures.find(path);
    if (it != m_textures.end()) {
        return it->second;
    }

    SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        m_textures[path] = newTexture;
    }

    SDL_FreeSurface(loadedSurface);

    return newTexture;
}

SDL_Texture *BAssets::getTexture(const std::string &id) {
    auto it = m_textures.find(id);
    if (it != m_textures.end()) {
        return it->second;
    }
    return nullptr;
}

bool BAssets::releaseTexture(const std::string &id) {
    auto it = m_textures.find(id);
    if (it != m_textures.end()) {
        if (it->second != nullptr) {
            SDL_DestroyTexture(it->second);
        }
        m_textures.erase(it);
        return true;
    }
    return false;
}

void BAssets::releaseAll() {
    for (auto &pair: m_textures) {
        if (pair.second != nullptr) {
            SDL_DestroyTexture(pair.second);
        }
    }
    m_textures.clear();
}
