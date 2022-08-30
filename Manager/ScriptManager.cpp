/*****************************************************************************
FileName:   ScriptManager.cpp
Author:     Xeler
Desc:       Desc
******************************************************************************/

#include "ScriptManager.h"
#include <random>

BE_USE

ScriptManager::ScriptManager() {

}

ScriptManager::~ScriptManager() {

}

std::string ScriptManager::pretreatment(char *code) {
    std::string operands, operators;
    std::string encode;
    return encode;
}

double ScriptManager::execute(std::string expression) {
    unsigned long point = 0, cache = 0;
    unsigned char operatorIndex;
    std::stack<double> operandStack;
    std::string varKey, operatorString;
    operandStack.push(0.0);
    while (point <= expression.length()) {
        if (expression[point] >= '0' && expression[point] <= '9') {
            cache = (cache * 10) + (expression[point] - 48);
        } else {
            while ((point <= expression.length()) && (operatorIndex != -1))
                operatorIndex = 0;
        }
        point++;
    }
    return 0;
}

BEvent ScriptManager::analysis(std::string code) {
    ManagerType toWhere = ScriptSys;
    return BEvent(ScriptSys, toWhere, code);
}

void *ScriptManager::memoryWrite(std::string key, void *value) {
    return nullptr;
}

void *ScriptManager::memoryRead(std::string key) {
    return nullptr;
}

unsigned char ScriptManager::getOperatorIndex(std::string operatorString) {
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

void ScriptManager::processEvent(BEvent event) {
    
}
