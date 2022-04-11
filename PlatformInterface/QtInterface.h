/*****************************************************************************
FileName:   QtInterface.h
Creater:    Xeler
Desc:       QtInterface define.
******************************************************************************/

#ifndef BALLENGINE4CPP_QTINTERFACE_H
#define BALLENGINE4CPP_QTINTERFACE_H

#include "../Core/define.h"
#include "../Core/SystemInterface.h"

#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QApplication>

BE_USE

class QtInterface : public SystemInterface {
public:
    explicit QtInterface(int argc, char *argv[]);

    ~QtInterface();

    void updateFrame(BImage frame) override;

    void processEvent(BEvent event) override;

    int execute();

private:
    QApplication qtApplication;
    QLabel qtScreen;
};

#endif //BALLENGINE4CPP_QTINTERFACE_H
