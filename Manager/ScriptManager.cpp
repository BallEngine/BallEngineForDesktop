/*****************************************************************************
FileName:   ScriptManager.cpp
Creater:    Xeler
Date:       2021/04/20
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "ScriptManager.h"

_BE_USE

ScriptManager::ScriptManager() {

}

ScriptManager::~ScriptManager() {

}

int ScriptManager::execute(BString code) {
return 0;
}

Event ScriptManager::analysis(BString code) {
    ManagerType toWhere = ScriptSys;
    return Event(ScriptSys, toWhere, BString("A"));
}

BString ScriptManager::pretreatment(char *code) {
    BString encode = BString(code);
    return encode;
}