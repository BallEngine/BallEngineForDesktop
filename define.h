/*****************************************************************************
FileName:   define.h
Creater:    Zekai Zhao
Date:       2020/12/5
Desc:       Define macro and type.
Version:    0.1
******************************************************************************/
1
#ifndef BALLENGINE4CPP_DEFINE_H
#define BALLENGINE4CPP_DEFINE_H

#define WIN32
//#define LINUX

#define _BE_BEGIN namespace be{
#define _BE_END   }
#define _BE_USE   using namespace be;

#define emitNewEvent(x, y) (emit(Event(this,y,x)))
#define emitEvent(x) (emit(x))

#include "Other/BString.h"
#include "Other/BImage.h"
#include "Helper/INFHelper.h"
#include "Helper/NetHelper.h"

#endif //BALLENGINE4CPP_DEFINE_H
