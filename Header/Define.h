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

#define BE_BEGIN    namespace BE{
#define BE_END      }
#define BE_USE      using namespace BE;

#define emitNewEvent(from,target,message)  (BallEngine::emitBEvent(BEvent(from,target,message)))

typedef unsigned long long PtrNum;

#endif //BALLENGINE_DEFINE_H
