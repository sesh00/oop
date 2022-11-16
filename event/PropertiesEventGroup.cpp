#include "PropertiesEventGroup.h"

#include "Player.h"
#include "Controller.h"
void HealAppliedEvent::emitEvent() {
    int health = player->getHealth();
    player->setHealth(health + 1);

    field->setRandomFeature();
}

void CoinAppliedEvent::emitEvent() {
    int coins = player->getCoins();
    player->setCoins(coins + 1);

    field->setRandomFeature();
}

void NothingAppliedEvent::emitEvent() {
    field->setRandomFeature();
}
