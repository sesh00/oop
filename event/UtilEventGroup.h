#pragma once
#ifndef OOP_UTILEVENTGROUP_H
#define OOP_UTILEVENTGROUP_H

#include "Event.h"

class UtilEventGroup : public Event{
public:
    virtual void emitEvent() = 0;
    virtual Event* clone() = 0;
    ~UtilEventGroup() override = default;
};

class PortalActivatedEvent: public UtilEventGroup{
public:
    Event* clone() override{ return new PortalActivatedEvent; }
    void emitEvent() override;
};

#endif //OOP_UTILEVENTGROUP_H
