#pragma once
#ifndef OOP_COMMANDREADER_H
#define OOP_COMMANDREADER_H


#include <string>
#include <iostream>
#include "PlayAction.h"


class CommandReader {
public:
    explicit CommandReader() = default;
    void getUserCommand();
    std::pair<int,int> getFieldSize();
    std::pair<int,int> getLoggerProperties();
    Prefix* getLoggerLevels();
    ~CommandReader() = default;
private:
    int fieldWidth;
    int fieldHeight;
    int isConsoleLogger;
    int isFileLogger;
    Prefix levels[3];
};

#endif //OOP_COMMANDREADER_H
