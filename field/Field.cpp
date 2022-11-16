#include "Field.h"

#include <utility>

namespace {
    auto randomizer = std::mt19937 (std::random_device{}());

    int rand_int(int from, int to) {
        return std::uniform_int_distribution<int>(from, to)(randomizer);
    }
}

std::pair<int,int> Field::getPlayerPos(){
    return {playerPosX, playerPosY};
};

std::pair<int,int> Field::getFieldSize(){
    return {fieldWidth, fieldHeight};
};

void Field::initPlayer() {
    playerPosX = rand_int(0, fieldHeight - 1);
    playerPosY = rand_int(0, fieldWidth - 1);
    fieldGrid[playerPosX][playerPosY].setFeature(specialFeatureList[1]);
    fieldGrid[playerPosX][playerPosY].setPassable(true);
}

void Field::initPortal() {
    this-> portalPosX = fmax(fieldHeight - playerPosX, playerPosX)/2;
    this -> portalPosY = fmax(fieldWidth - playerPosY, playerPosY)/2;

    fieldGrid[portalPosX][portalPosY].setFeature(specialFeatureList[2]);
    fieldGrid[portalPosX][portalPosY].setPassable(true);
}

void Field::movePlayer(int playerPosX_, int playerPosY_, bool tp) {

    if (tp){
        playerPosX_ = rand_int(0, fieldHeight - 1);
        playerPosY_ = rand_int(0, fieldWidth - 1);
        fieldGrid[playerPosX_][playerPosY_].setPassable(true);
    }

    if (fieldGrid[playerPosX_][playerPosY_].getPassable()){
        fieldGrid[playerPosX][playerPosY].setFeature(specialFeatureList[0]);
        playerPosX = playerPosX_;
        playerPosY = playerPosY_;
        Event* event = fieldGrid[playerPosX_][playerPosY_].getEvent();
        fieldGrid[playerPosX_][playerPosY_].setFeature(specialFeatureList[1]);
        event -> init(controller);
        event -> emitEvent();
        InitMessage(GAMEMESSAGE,"New event has been emitted");

    } else InitMessage(ERRORMESSAGE,"Attempt to enter an impassable cell");


}

Cell Field::getCell(int posX, int posY) {
    return this->fieldGrid.at(posX).at(posY);
}

void Field::setRandomFeature(){
    int randPosX = rand_int(0, fieldHeight - 1);
    int randPosY = rand_int(0, fieldWidth - 1);
    int pos_ = rand_int(0, static_cast<int>(featureList.size()) - 1);

    if (randPosY == playerPosY && randPosX == playerPosX){ return; }
    if (randPosY == portalPosY && randPosX == portalPosX){ return; }

    CellFeature* feature = featureList.at(pos_);
    fieldGrid[randPosX][randPosY].setFeature(feature);

    if (pos_){
        fieldGrid[randPosX][randPosY].setPassable(true);
    } else {
        fieldGrid[randPosX][randPosY].setPassable(false);
    }

    InitMessage(STATEMESSAGE, "New feature has been created\n");

}

Field::Field(Controller* controller, int fieldWidth, int fieldHeight):
controller(controller), fieldWidth(fieldWidth), fieldHeight(fieldHeight){

    if (fieldWidth <= 0 || fieldHeight <= 0){
        return;
    }

    featureList = {new WallFeature, new EnemyFeature, new HealFeature,
                   new CoinFeature, new TrapFeature, new TeleportFeature};

    specialFeatureList = {new EmptyFeature, new PlayerFeature, new PortalFeature};

    for(int row = 0; row < fieldHeight; ++row){
        fieldGrid.push_back(std::vector<Cell>());
        for(int col = 0; col < fieldWidth; ++col){
            fieldGrid.back().emplace_back(Cell(true));
        }
    }

    for (int item = 0; item < (fieldWidth * fieldHeight)/ITEMS; item++){
        setRandomFeature();
    }

    initPlayer();
    initPortal();

}

Field::Field(const Field &other) {
    this->fieldWidth = other.fieldWidth;
    this->fieldHeight = other.fieldHeight;
    this->playerPosX = other.playerPosX;
    this->playerPosY = other.playerPosY;

    Grid fg(this->fieldHeight, std::vector<Cell>(this->fieldWidth));

    for(int row = 0; row < fieldHeight; ++row){
        for(int col = 0; col < fieldWidth; ++col){
            fg[playerPosX][playerPosY] = other.fieldGrid[playerPosX][playerPosY];
        }
    }

    this->fieldGrid = fg;
}

void Field::swap(Field &other) {
    std::swap(this->fieldWidth, other.fieldWidth);
    std::swap(this->fieldHeight, other.fieldHeight);
    std::swap(this->playerPosX, other.playerPosX);
    std::swap(this->playerPosY, other.playerPosY);
    std::swap(this->fieldGrid, other.fieldGrid);
}

Field &Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);
    return *this;
}

Field &Field::operator=(Field &&other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

Field::Field(Field &&other) noexcept {
    this->swap(other);
}