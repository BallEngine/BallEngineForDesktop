/*****************************************************************************
FileName:   define.h
Creater:    Zekai Zhao
Desc:       Define macro and type.
Version:    0.1
******************************************************************************/

#ifndef BALLENGINE4CPP_DEFINE_H
#define BALLENGINE4CPP_DEFINE_H

#define WIN32
//#define LINUX

#define CLASS_OPTION protected
#define CLASS_INTERFACE public

#define OPTION_SINGLETON_CLASS(CLASSNAME) explicit CLASSNAME() {}; CLASSNAME(CLASSNAME &) = delete; CLASSNAME &operator=(const CLASSNAME &input) = delete;

#define INTERFACE_INSTANTIATION(CLASSNAME) static CLASSNAME &instantiation() {static CLASSNAME *instance = nullptr;if (instance == nullptr) {instance = new CLASSNAME();}return *instance;};

#define BE_BEGIN namespace be{
#define BE_END   }
#define BE_USE   using namespace be;

#define emitNewEvent(x, y) (emit(Event(this,y,x)))
#define emitEvent(x) (emit(x))

#include "Other/BString.h"
#include "Other/BImage.h"
#include "Helper/INFHelper.h"
#include "Helper/NetHelper.h"

#endif //BALLENGINE4CPP_DEFINE_H
