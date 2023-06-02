#include <iostream>
#include <SDL2/SDL.h>
#include "Core/BallEngine.h"

#undef main

int main(int argc, char *argv[]) {
    BallEngine &ballEngine = BallEngine::instantiation();

    ballEngine.initialization();



    return 0;
}