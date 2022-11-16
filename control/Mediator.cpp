#include "Mediator.h"

void Mediator::startGame() {
    controller->showField();
    controller->showProperties();

    while(controlCommand->setAction()){
        int playAction = controlCommand->getAction();
        this->controller->takeAction(playAction);
        controller->showField();
        controller->showProperties();

        if(controller->state == Controller::Win){
            controller->showGameWin();
            return;
        }
        if(controller->state == Controller::Lose){
            controller->showGameOver();
            return;
        }

    }
}

Mediator::Mediator(Controller* controller, CommandReader* commandReader) {
    this->controller = controller;
    this->commandReader = commandReader;
    this->controlCommand = new ControlCommand;
}

