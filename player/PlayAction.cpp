#include "PlayAction.h"

void NoneAction::action(){

}

void MoveLeftAction::action(){
    auto [playerPosX, playerPosY] = field->getPlayerPos();
    auto [fieldWidth, fieldHeight] = field->getFieldSize();
    playerPosY = playerPosY - 1 >= 0 ? playerPosY - 1 : fieldWidth - 1;
    field->movePlayer(playerPosX, playerPosY);
}

void MoveUpAction::action(){
    auto [playerPosX, playerPosY] = field->getPlayerPos();
    auto [fieldWidth, fieldHeight] = field->getFieldSize();
    playerPosX = playerPosX - 1 >= 0 ? playerPosX - 1 : fieldHeight - 1;
    field->movePlayer(playerPosX, playerPosY);
}

void MoveDownAction::action(){
    auto [playerPosX, playerPosY] = field->getPlayerPos();
    auto [fieldWidth, fieldHeight] = field->getFieldSize();
    playerPosX = (playerPosX + 1) % fieldHeight;
    field->movePlayer(playerPosX, playerPosY);
}

void MoveRightAction::action(){
    auto [playerPosX, playerPosY] = field->getPlayerPos();
    auto [fieldWidth, fieldHeight] = field->getFieldSize();
    playerPosY = (playerPosY + 1) % fieldWidth;
    field->movePlayer(playerPosX, playerPosY);
}

void TpAction::action(){
    auto [playerPosX, playerPosY] = field->getPlayerPos();
    auto [fieldWidth, fieldHeight] = field->getFieldSize();

    field->movePlayer(NULL,NULL,true);
}


void PlayAction::init(Player* player, Field* field) {
    this -> field = field;
    this -> player = player;
}
