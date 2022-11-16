#include "EnemyEventGroup.h"

#include "Controller.h"

void TrapActivatedEvent::emitEvent() {
    int coins = player->getCoins();
    int health = player->getHealth();

    player->setCoins(coins-1);
    player->setHealth(health-1);

    if (player->getHealth() == 0){
        controller->setState(Controller::Lose);
    }

    field->setRandomFeature();

}

void EnemyActivatedEvent::emitEvent() {
    int health = player->getHealth();
    player->setHealth(health-1);
    controller->takeAction(ActionPrefix::UP);

    if (player->getHealth() == 0){
        controller->setState(Controller::Lose);
    }

    field->setRandomFeature();
}

void TeleportActivatedEvent::emitEvent() {
    int coins = player->getCoins();

    if (coins > 0){
        player->setCoins(coins-1);
        controller->takeAction(ActionPrefix::TP);
    }
    field->setRandomFeature();
}
