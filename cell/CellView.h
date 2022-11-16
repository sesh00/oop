#pragma once
#ifndef OOP_CELLVIEW_H
#define OOP_CELLVIEW_H


#include "Cell.h"

class CellView {
public:
    CellView(Cell c);
    std::string getView();
    CellFeature::Color getColor();
private:
    std::string view;
    CellFeature::Color color;
};


#endif //OOP_CELLVIEW_H
