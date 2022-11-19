#include "Controller.h"
#include <list>
#include <Observer.h>

Controller::Controller(Logger* logger, const Prefix* prefixList,
                       int fieldWidth, int fieldHeight) : state(None) {

    this->player = new Player;
    this->field = new Field(this, fieldWidth, fieldHeight);
    this->fieldView = FieldView(field);

    this->controlConfig = new FileConfig("config.txt");

    observerList = {new Observer(*player, *logger),
                    new Observer(*field, *logger),
                    new Observer(*this, *logger),
                    new Observer(*controlConfig, *logger)
    };

    for(int p = 0; p < 3; p++){
        Prefix pref = prefixList[p];
        switch(pref){
            case ERRORMESSAGE:
                Subscriber::attach(pref, new ErrorMessage);
                break;
            case STATEMESSAGE:
                Subscriber::attach(pref, new StateMessage);
                break;
            case GAMEMESSAGE:
                Subscriber::attach(pref, new GameMessage);
                break;
            default:
                break;
        }
    }

    if (fieldWidth <= 0 || fieldHeight <= 0)
        InitMessage(ERRORMESSAGE, "Size of field has an incorrect value");


    for(auto action : controlConfig->initConfig()){
        auto pair = action.second;
        pair.second->init(player, field);
    }
}

void Controller::showField() {
    fieldView.showField();
}

void Controller::setState(State state) {
    this->state = state;
}

void Controller::showGameOver() {
    fieldView.showGameOver();
    InitMessage(STATEMESSAGE,"The game was lost");
}

void Controller::showGameWin() {
    fieldView.showGameWin();
    InitMessage(STATEMESSAGE, "The game was won");

}

void Controller::showProperties() {
    fieldView.showProperties(player);
}

void Controller::takeAction(int actionIndex) {
    for(auto action : controlConfig->initConfig()){
        auto pair = action.second;
        if (pair.first == actionIndex)
            pair.second->action();
    }
}

void Controller::takeAction(ActionPrefix actionPrefix) {
    for(auto action : controlConfig->initConfig()){
        auto pair = action.second;
        if (action.first == actionPrefix)
            pair.second->action();
    }
}