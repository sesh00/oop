#pragma once
#ifndef OOP_FACTORY_H
#define OOP_FACTORY_H

#include "EnemyEventGroup.h"
#include "PropertiesEventGroup.h"
#include "UtilEventGroup.h"
class AbstractFactory {
public:
    virtual Event* makeItem(int choice) = 0;
};


class EnemyFactory: public AbstractFactory {
public:
    Event* makeItem(int choice) override;
private:
    Event* e_prototypes[3] = {new TrapActivatedEvent, new EnemyActivatedEvent, new TeleportActivatedEvent} ;
};


class PropertyFactory: public AbstractFactory {
public:
    Event* makeItem(int choice) override;

private:
    Event* p_prototypes[3] = {new HealAppliedEvent, new CoinAppliedEvent, new NothingAppliedEvent} ;
};

class UtilFactory: public AbstractFactory {
public:
    Event* makeItem(int choice) override;

private:
    Event* u_prototypes[1] = {new PortalActivatedEvent } ;
};



#endif //OOP_FACTORY_H
