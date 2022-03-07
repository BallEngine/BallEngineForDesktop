/*****************************************************************************
FileName:   ScriptManager.cpp
Creater:    Xeler
Desc:       Desc
Version:    0.1
******************************************************************************/

#include "ScriptManager.h"
#include <random>

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
    unsigned long point = 0, cache = 0;
    unsigned char operatorIndex;
    std::stack<double> operandStack;
    BString varKey, operatorString;
    operandStack.push(0.0);
    while (point <= expression.getLength()) {
        if (expression[point] >= '0' && expression[point] <= '9') {
            cache = (cache * 10) + (expression[point] - 48);
        } else {
            while ((point <= expression.getLength()) && (operatorIndex != -1))
                operatorIndex = 0;
        }
        point++;
    }
    return 0;
}

BEvent ScriptManager::analysis(BString code) {
    ManagerType toWhere = ScriptSys;
    return BEvent(ScriptSys, toWhere, BString("A"));
}

void *ScriptManager::memoryWrite(BString key, void *value) {
    return nullptr;
}

void *ScriptManager::memoryRead(BString key) {
    return nullptr;
}

unsigned char ScriptManager::getOperatorIndex(BString operatorString) {
    if (operatorString == "(") { return 0; };
    if (operatorString == ")") { return 1; };
    if (operatorString == "[") { return 2; };
    if (operatorString == "]") { return 3; };
    if (operatorString == "!") { return 4; };
    if (operatorString == "*") { return 5; };
    if (operatorString == "/") { return 6; };
    if (operatorString == "%") { return 7; };
    if (operatorString == "+") { return 8; };
    if (operatorString == "-") { return 9; };
    if (operatorString == "<") { return 10; };
    if (operatorString == ">") { return 11; };
    if (operatorString == "<=") { return 12; };
    if (operatorString == ">=") { return 13; };
    if (operatorString == "==") { return 14; };
    if (operatorString == "!=") { return 15; };
    if (operatorString == "&") { return 16; };
    if (operatorString == "|") { return 17; };
    if (operatorString == "=") { return 18; };
    if (operatorString == ",") { return 19; };
    if (operatorString == ";") { return 20; };
    return -1;
}
