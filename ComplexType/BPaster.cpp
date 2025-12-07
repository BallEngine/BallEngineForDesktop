/*****************************************************************************
FileName:   BPaster.cpp
Author:     Xeler
Desc:       Paster class.
******************************************************************************/

#include "BPaster.h"

BE_USE

BPaster::BPaster() {
}

BPaster::BPaster(const std::string &defaultTag, SDL_Surface pics[], unsigned int picCount, SDL_Renderer* renderer) {
    int i = 0;
    std::vector<SDL_Texture*> *list = new std::vector<SDL_Texture*>;
    while (i < picCount) {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, &pics[i]);
        list->push_back(texture);
        i++;
    }
    std::pair<std::string, std::vector<SDL_Texture*> *> defaultPair("default", list);
    std::pair<std::string, std::vector<SDL_Texture*> *> texturePair(defaultTag, list);

    m_textures.insert(defaultPair);
    m_textures.insert(texturePair);
}


BPaster::~BPaster() {
    pictures.clear();
}

BPaster &BPaster::operator=(const BPaster &paster) {
    this->m_picPoint = paster.m_picPoint;
    auto ic = paster.pictures.begin();
    while (ic != pictures.end()) {
        this->pictures.push_back(*ic);
        ++ic;
    }
    return *this;
}

void BPaster::setFrame(int frameNumber) {
    if (m_picPoint + frameNumber > 0) {
        m_picPoint += frameNumber;
    } else {
        m_picPoint = 0;
    }
}

SDL_Surface BPaster::getFrame() {
    if (!(m_picPoint < m_textures.at(m_activeTag)->size())) {
        m_picPoint = 0;
    }
    return m_textures.at(m_activeTag)->[m_picPoint++];
}

void BPaster::bindAction(PasterAction actionType, std::string actionScript) {

}

void BPaster::setPos(PosPair pos) {

}

PosPair BPaster::getPos() {
    return m_pasterPos;
}

void BPaster::addPicList(std::string tag, SDL_Surface *pics, unsigned int picCount) {

}
