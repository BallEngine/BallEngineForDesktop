/*****************************************************************************
FileName:   GLInterface.h
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_GLINTERFACE_H
#define BALLENGINE4CPP_GLINTERFACE_H

#include "../Core/define.h"
#include "../Core/SystemInterface.h"
//#include <GL/glew.h>
//#include <GL/freeglut.h>


BE_BEGIN

    class GLInterface : public SystemInterface {
    public:
        void processEvent(BEvent event);
    };

BE_END

#endif //BALLENGINE4CPP_GLINTERFACE_H
