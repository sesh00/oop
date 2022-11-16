#pragma once
#ifndef OOP_ENEMYEVENTGROUP_H
#define OOP_ENEMYEVENTGROUP_H


#include <iostream>
#include "Event.h"

class EnemyEventGroup : public Event{
public:
    virtual void emitEvent() = 0;
    virtual Event* clone() = 0;
    ~EnemyEventGroup() override = default;
};

class TrapActivatedEvent : public EnemyEventGroup {
public:
    Event* clone() override { return new TrapActivatedEvent; }
    void emitEvent() override;
};

class EnemyActivatedEvent : public EnemyEventGroup{
public:
    Event* clone() override{ return new EnemyActivatedEvent; }
    void emitEvent() override;
};

class TeleportActivatedEvent : public EnemyEventGroup {
public:
    Event* clone() override { return new TeleportActivatedEvent; }
    void emitEvent() override;
};


#endif //OOP_ENEMYEVENTGROUP_H
