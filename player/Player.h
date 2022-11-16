#pragma once
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <tuple>
#include <Observer.h>

class Player: public Subscriber {
public:
    Player(int health = 3, int coins = 0, int power = 100);

    std::tuple<int, int, int> getProperties();
    void setProperties(int health, int coins, int power);

    int getHealth();
    int getCoins();
    int getPower();

    void setHealth(int health);
    void setCoins(int coins);
    void setPower(int power);

private:
    int health, coins, power;
    std::tuple<int, int, int> properties;


};


#endif //OOP_PLAYER_H
