#pragma once
#ifndef OOP_EVENT_H
#define OOP_EVENT_H

class Controller;
class Player;
class Field;

class Event {
public:
    virtual void emitEvent() = 0;
    virtual Event* clone() = 0;
    virtual ~Event() = default;
    void init(Controller* controller);

protected:
    Controller* controller;
    Player* player;
    Field* field;
};


#endif //OOP_EVENT_H
