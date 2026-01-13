/*****************************************************************************
FileName:   define.h
Author:     Xeler
Desc:       Declare macro and type.
******************************************************************************/

#ifndef BALLENGINE_SINGLETON_CLASS_H
#define BALLENGINE_SINGLETON_CLASS_H

#include <memory>
#include <mutex>

#define SINGLETON_CLASS(CLASSNAME) \
CLASSNAME(); \
CLASSNAME(const CLASSNAME&) = delete; \
CLASSNAME& operator=(const CLASSNAME&) = delete; \
public: \
    static CLASSNAME& getInstance() { \
        static CLASSNAME instance; \
        return instance; \
    }
#endif //BALLENGINE_SINGLETON_CLASS_H
