/*****************************************************************************
FileName:   QtInterface.h
Creater:    Xeler
Desc:       QtInterface define.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_QTINTERFACE_H
#define BALLENGINE4CPP_QTINTERFACE_H

#include "../define.h"
#include "../Template/SystemInterface.h"

BE_USE

class QtBallEngine : public BallEngine {
public:
    QtBallEngine();

    ~QtBallEngine();
};


class QtInterface : public SystemInterface {
public:
    BallEngine *createEngine();
    SystemInterface getInterface();
    BImage updateFrame();
    void *castPasterToPic();
    void processEvent(Event event);
private:
    QtInterface();
    ~QtInterface();
};

#endif //BALLENGINE4CPP_QTINTERFACE_H
