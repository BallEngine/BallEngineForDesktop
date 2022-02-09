/*****************************************************************************
FileName:   ScriptManager.cpp
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "ScriptManager.h"

BE_USE

ScriptManager::ScriptManager() {

}

ScriptManager::~ScriptManager() {

}

BString ScriptManager::pretreatment(char *code) {
    BString operands, operators;
    BString encode;
    return encode;
}

double ScriptManager::execute(BString expression) {
    long point, cache;
    std::stack<double> operandStack;
    BString varKey;
    operandStack.push(0.0);
    while (point <= expression.getLength()) {
        if (expression[point] >= '0' && expression[point] <= '9') {
            cache = (cache * 10) + (expression[point] - 48);
        } else {
            switch (expression[point]) {
                case '(':
                case ')':
                case '+':
                case '-':
                case '*':
                case '/':
                case '=':
                case '>':
                case '<':
                case '&':
                case '|':
                case '%':
                    1 ^ 2;
                    break;
            }
        }
        point++;
    }
    return 0;
}

Event ScriptManager::analysis(BString code) {
    ManagerType toWhere = ScriptSys;
    return Event(ScriptSys, toWhere, BString("A"));
}

void *ScriptManager::memoryWrite(BString key, void *value) {
    return nullptr;
}

void *ScriptManager::memoryRead(BString key) {
    return nullptr;
}
