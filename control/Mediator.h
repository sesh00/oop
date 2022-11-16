#pragma once
#ifndef OOP_MEDIATOR_H
#define OOP_MEDIATOR_H


#include <map>
#include "Controller.h"
#include "CommandReader.h"
#include "ControlCommand.h"

class Mediator {
public:
    Mediator(Controller *controller, CommandReader *commandReader);
    ~Mediator() = default;
    void startGame();

private:
    Controller* controller;
    CommandReader* commandReader;
    ControlCommand* controlCommand;
};


#endif //OOP_MEDIATOR_H
