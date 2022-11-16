#include "Cell.h"


Cell::Cell(bool isPassable):
isPassable(isPassable){
    this -> obj = new EmptyFeature;
    this -> event = obj -> execute();
}

void Cell::setEvent(Event *event) {
    this -> event = event;
}

Event* Cell::getEvent() {
    return this -> event;
}

void Cell::setPassable(bool isPassable){
    this -> isPassable = isPassable;
}

bool Cell::getPassable() const{
    return isPassable;

}

void Cell::setFeature(CellFeature* feature){
    this -> obj = feature;
    this -> event = obj -> execute();
}

CellFeature* Cell::getFeature(){
    return this->obj;
}


Cell &Cell::operator=(Cell &&other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell::Cell(Cell &&other)  noexcept {
    this->swap(other);
}

Cell &Cell::operator=(const Cell &other) {
    if (this != &other)
        Cell(other).swap(*this);
    return *this;
}



void Cell::swap(Cell &other) {
    std::swap(obj, other.obj);
    std::swap(event, other.event);

    bool temp = this->isPassable;
    this->isPassable = other.isPassable;
    other.isPassable = temp;
}