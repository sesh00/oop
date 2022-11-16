#pragma once
#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H

#include <windows.h>
#include <iostream>
#include <CellView.h>
#include "Field.h"

class FieldView {
public:
    explicit FieldView(Field *other);
    FieldView() = default;
    void showField();
    void showGameOver();
    void showGameWin();

    void showProperties(Player* player);
private:
    Field *obj;
};

#endif //OOP_FIELDVIEW_H
