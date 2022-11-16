#include "Player.h"

Player::Player(int health, int coins, int power):
        health(health), coins(coins), power(power) {
    properties = std::make_tuple(health, coins, power);
}

int Player::getHealth(){
    return health;
}
int Player::getCoins(){
    return coins;
}
int Player::getPower(){
    return power;
}


std::tuple<int, int, int> Player::getProperties(){
    return std::make_tuple(health, coins, power);

}
void Player::setProperties(int health, int coins, int power){
    std::get<0>( properties) = health;
    std::get<1>( properties) = coins;
    std::get<2>( properties) = power;

}

void Player::setHealth(int health){
    this -> health = health;
    InitMessage(GAMEMESSAGE,"Health has been changed");
}

void Player::setCoins(int coins){
    this -> coins = coins;
    InitMessage(GAMEMESSAGE,"Coins has been changed");
}

void Player::setPower(int power){
    this -> power = power;
    InitMessage(GAMEMESSAGE, "Power has been changed");
}


