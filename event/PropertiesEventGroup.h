#pragma once
#ifndef OOP_PROPERTIESEVENTGROUP_H
#define OOP_PROPERTIESEVENTGROUP_H

#include "Event.h"
#include <iostream>

class PropertyEventGroup : public Event {
public:
    virtual void emitEvent() = 0;
    virtual Event* clone() = 0;
    ~PropertyEventGroup() override = default;
};
class HealAppliedEvent : public PropertyEventGroup {
public:
    Event* clone() override { return new HealAppliedEvent; }
    void emitEvent() override;
};

class CoinAppliedEvent: public PropertyEventGroup{
public:
    Event* clone() override{ return new CoinAppliedEvent; }
    void emitEvent() override;
};

class NothingAppliedEvent: public PropertyEventGroup{
public:
    Event* clone() override{ return new NothingAppliedEvent; }
    void emitEvent() override;
};
#endif //OOP_PROPERTIESEVENTGROUP_H
