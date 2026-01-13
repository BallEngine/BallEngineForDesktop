#include "Core/BallEngine.h"

#undef main

int main(int argc, char *argv[]) {
    BallEngine &ballEngine = BallEngine::getInstance();

    ballEngine.init();

    return 0;
}