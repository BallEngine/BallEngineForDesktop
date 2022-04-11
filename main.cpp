#include <iostream>
#include <QApplication>
#include <QWidget>
#include "Core/BallEngine.h"
#include "PlatformInterface/QtInterface.h"

int main(int argc, char *argv[]) {
    BallEngine &ballEngine = BallEngine::instantiation();
    QtInterface qtInterface(argc,argv);

    return qtInterface.execute();
}