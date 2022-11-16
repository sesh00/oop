#pragma once
#ifndef OOP_CELL_H
#define OOP_CELL_H


#include "../event/Event.h"
#include "CellFeature.h"
#include <algorithm>

class Cell {
public:

    void setPassable(bool isPassable);
    bool getPassable() const;

    void setEvent(Event *event);
    Event* getEvent();
    void setFeature(CellFeature* feature);
    CellFeature* getFeature();

    explicit Cell(bool isPassable = true);


    Cell(const Cell& other) = default;
    ~Cell() = default;


    Cell(Cell&& other) noexcept ;
    Cell& operator=(Cell&& other) noexcept ;


    Cell& operator=(const Cell& other);


private:
    CellFeature* obj;
    Event *event;

    bool isPassable;
    void swap(Cell &other);
};


#endif //OOP_CELL_H
