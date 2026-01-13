/*****************************************************************************
FileName:   ScriptManager.cpp
Author:     Xeler
Desc:       Script manager implementation for BallEngine
******************************************************************************/

#include "ScriptManager.h"

BE_USE

ScriptManager::ScriptManager() {
}

ScriptManager::~ScriptManager() {
}

std::string ScriptManager::pretreatment(const char *code) {
    std::string operands, operators;
    std::string encode;
    if (code != nullptr) {
        std::string codeStr(code);
        for (char c: codeStr) {
            if (std::isdigit(c) || std::isalpha(c) || c == '.') {
                operands += c;
            } else if (std::strchr("+-*/%()[]!<>=", c)) {
                operators += c;
            }
        }
        encode = operands + operators;
    }
    return encode;
}

double ScriptManager::execute(const std::string &expression) {
    unsigned long point = 0, cache = 0;
    std::stack<double> operandStack;
    std::string varKey, operatorString;
    operandStack.push(0.0);

    while (point < expression.length()) {
        if (std::isdigit(expression[point])) {
            cache = (cache * 10) + (expression[point] - '0');
        } else {
            if (cache > 0) {
                operandStack.push(cache);
                cache = 0;
            }

            operatorString = expression[point];
            if (point + 1 < expression.length() &&
                (expression[point] == '=' || expression[point] == '<' || expression[point] == '>')) {
                if (expression[point + 1] == '=') {
                    operatorString += expression[point + 1];
                    point++;
                }
            }

            unsigned char operatorIndex = getOperatorIndex(operatorString);

            if (cache > 0) {
                operandStack.push(cache);
                cache = 0;
            }
        }
        point++;
    }

    if (cache > 0) {
        operandStack.push(static_cast<double>(cache));
    }

    if (!operandStack.empty()) {
        return operandStack.top();
    }
    return 0.0;
}

BEvent ScriptManager::analysis(std::string code) {
    ManagerType toWhere = ScriptSys;
    return BEvent(ScriptSys, toWhere, std::move(code));
}

void ScriptManager::memoryWrite(const std::string &key, int value) {
    memoryMap[key] = value;
}

int ScriptManager::memoryRead(const std::string &key) {
    auto it = memoryMap.find(key);
    if (it != memoryMap.end()) {
        return it->second;
    }
    return 0;
}

unsigned char ScriptManager::getOperatorIndex(const std::string &operatorString) {
    if (operatorString == "(") { return 0; }
    if (operatorString == ")") { return 1; }
    if (operatorString == "[") { return 2; }
    if (operatorString == "]") { return 3; }
    if (operatorString == "!") { return 4; }
    if (operatorString == "*") { return 5; }
    if (operatorString == "/") { return 6; }
    if (operatorString == "%") { return 7; }
    if (operatorString == "+") { return 8; }
    if (operatorString == "-") { return 9; }
    if (operatorString == "<") { return 10; }
    if (operatorString == ">") { return 11; }
    if (operatorString == "<=") { return 12; }
    if (operatorString == ">=") { return 13; }
    if (operatorString == "==") { return 14; }
    if (operatorString == "!=") { return 15; }
    if (operatorString == "&") { return 16; }
    if (operatorString == "|") { return 17; }
    if (operatorString == "=") { return 18; }
    if (operatorString == ",") { return 19; }
    if (operatorString == ";") { return 20; }
    return 255;
}

void ScriptManager::processEvent(BEvent event) {
    std::string eventData = event.data;
}
