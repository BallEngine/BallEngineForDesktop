#include <iostream>
#include <SDL2/SDL.h>
#include "Core/BallEngine.h"

#undef main

int main(int argc, char *argv[]) {
    //be::BallEngine &ballEngine = be::BallEngine::instantiation();

    SDL_Init(SDL_INIT_EVERYTHING);

    //SDL_Surface *pic = SDL_LoadBMP("./assets.bmp");
    //SDL_Surface*optPic= SDL_Format;

    SDL_Window *screen = SDL_CreateWindow(argv[2], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);

    printf("Hello");

    SDL_Quit();
    return 0;
}