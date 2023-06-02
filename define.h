/*****************************************************************************
FileName:   define.h
Author:     Xeler
Desc:       Define macro and type.
******************************************************************************/

#ifndef BALLENGINE_DEFINE_H
#define BALLENGINE_DEFINE_H

#define BALLENGINE_VERSION  V0.2A

#define CLASS_OPTION    protected
#define CLASS_INTERFACE public

#define OPTION_SINGLETON_CLASS(CLASSNAME)   explicit CLASSNAME(); CLASSNAME(CLASSNAME &) = delete; CLASSNAME &operator=(const CLASSNAME &input) = delete;

#define INTERFACE_INSTANTIATION(CLASSNAME)  static CLASSNAME &instantiation() {static CLASSNAME *instance = nullptr;if (instance == nullptr) {instance = new CLASSNAME();}return *instance;};

#define BE_BEGIN    namespace BE{
#define BE_END      }
#define BE_USE      using namespace BE;

#define emitNewEvent(from,target,message)  (BallEngine::emitBEvent(BEvent(from,target,message)))

typedef unsigned long long PtrNum;

#endif //BALLENGINE_DEFINE_H
