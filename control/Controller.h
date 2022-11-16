#pragma once
#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H

#include "../player/Player.h"
#include "../field/Field.h"
#include "../field/FieldView.h"
#include "CommandReader.h"
#include "ControlConfig.h"
#include <list>

class Logger;
class Controller: public Subscriber {
public:
    enum State {
        None = 0,
        Win = 1,
        Lose = 3,
    };

    explicit Controller(Logger* logger,  const Prefix* prefixList,
                        int fieldWidth = 30, int fieldHeight = 35);
    void takeAction(int action);
    void takeAction(ActionPrefix actionPrefix);

    ~Controller() override = default;

    void showField();
    void showGameOver();
    void showGameWin();
    void setState(State state);
    void showProperties();

    Player* player;
    Field* field;
    State state;
private:
    ControlConfig* controlConfig;
    std::vector <Observer*> observerList;
    FieldView fieldView{};
};

#endif //OOP_CONTROLLER_H
