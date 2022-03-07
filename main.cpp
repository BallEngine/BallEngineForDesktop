#include <iostream>
#include <QApplication>
#include <QWidget>
#include "Core/BallEngine.h"
#include "PlatformInterface/QtInterface.h"

int main(int argc, char *argv[]) {
    BallEngine &ballEngine = BallEngine::instantiation();
    QtInterface anInterface = QtInterface();
    QApplication application(argc, argv);
    QWidget mainWidget;
    mainWidget.show();
    return application.exec();
}