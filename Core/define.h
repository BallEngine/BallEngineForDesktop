/*****************************************************************************
FileName:   define.h
Creater:    Zekai Zhao
Desc:       Define macro and type.
******************************************************************************/

#ifndef BALLENGINE4CPP_DEFINE_H
#define BALLENGINE4CPP_DEFINE_H

#define BALLENGINE_VERSION  V0.2A

#define CLASS_OPTION    protected
#define CLASS_INTERFACE public

#define OPTION_SINGLETON_CLASS(CLASSNAME)   explicit CLASSNAME() {}; CLASSNAME(CLASSNAME &) = delete; CLASSNAME &operator=(const CLASSNAME &input) = delete;

#define INTERFACE_INSTANTIATION(CLASSNAME)  static CLASSNAME &instantiation() {static CLASSNAME *instance = nullptr;if (instance == nullptr) {instance = new CLASSNAME();}return *instance;};

#define BE_BEGIN    namespace be{
#define BE_END      }
#define BE_USE      using namespace be;

#define emitNewEvent(x, y)  (BallEngine::emitBEvent(BEvent(this,y,x)))
#define emitEvent(x)        (BallEngine::emitBEvent(x))

#include "../BaseType/BString.h"
#include "../BaseType/BImage.h"
#include "../ComplexType/BPaster.h"
#include "../Helper/INFHelper.h"
#include "../Helper/NetHelper.h"

#endif //BALLENGINE4CPP_DEFINE_H
