#pragma once
#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include "LoggerGroup.h"
#include "GameLog.h"


class Logger {
    std::list<LoggerGroup*> m_Streams;
public:
    void attach(LoggerGroup *os);
    Logger &operator<<(Message* message);
};

#endif //OOP_LOGGER_H
