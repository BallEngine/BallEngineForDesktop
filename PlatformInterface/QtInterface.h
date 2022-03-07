/*****************************************************************************
FileName:   QtInterface.h
Creater:    Xeler
Desc:       QtInterface define.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_QTINTERFACE_H
#define BALLENGINE4CPP_QTINTERFACE_H

#include "../Core/define.h"
#include "../Core/SystemInterface.h"

#include <QImage>

BE_USE

class QtInterface : public SystemInterface {
public:
    explicit QtInterface();

    ~QtInterface();

    void updateFrame(BImage frame);

    void processEvent(BEvent event);
};

#endif //BALLENGINE4CPP_QTINTERFACE_H
