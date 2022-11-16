#pragma once
#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <vector>
#include "../cell/Cell.h"
#include "../player/Player.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include <Factory.h>

typedef std::vector<std::vector<Cell>> Grid;

class Field: public Subscriber {
public:
    Field(Controller* controller, int fieldWidth = 20, int fieldHeight = 25);

    void initPlayer();
    void movePlayer(int playerPosX_, int playerPosY_,  bool tp = false);
    void setRandomFeature();

    Cell getCell(int posX, int posY);
    std::pair<int,int> getPlayerPos();
    std::pair<int,int> getFieldSize();


    Field(Field &&other) noexcept;

    Field(const Field &other);

    ~Field() = default;

    Field &operator=(const Field &other);

    Field &operator=(Field &&other) noexcept;


private:
    int const ITEMS = 2;

    Controller* controller;
    int playerPosX, playerPosY;
    int fieldWidth, fieldHeight;
    std::vector <CellFeature*> featureList;
    std::vector <CellFeature*> specialFeatureList;
    Grid fieldGrid;
    void swap(Field &other);

    void initPortal();

    int portalPosX;
    int portalPosY;
};


#endif //OOP_FIELD_H
