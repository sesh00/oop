#include <Event.h>
#include "CellFeature.h"

Event * HealFeature::execute() {
    return propertyFactory->makeItem(0);
}

Event * EnemyFeature::execute() {
    return enemyFactory->makeItem(1);
}

Event * EmptyFeature::execute() {
    return propertyFactory->makeItem(2);
}

Event * WallFeature::execute() {
    return propertyFactory->makeItem(2);
}

Event * PlayerFeature::execute() {
    return propertyFactory->makeItem(2);
}

Event * CoinFeature::execute() {
    return propertyFactory->makeItem(1);
}

Event * TrapFeature::execute() {
    return enemyFactory->makeItem(0);
}

Event * TeleportFeature::execute() {
    return enemyFactory->makeItem(2);
}

Event *PortalFeature::execute() {
    return utilFactory->makeItem(0);
}

