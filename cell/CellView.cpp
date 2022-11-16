#include "CellView.h"

CellView::CellView(Cell cell) {
   this->view = cell.getFeature()->getView();
   this->color = cell.getFeature()->getColor();
}

std::string CellView::getView() {
    return this->view;
}

CellFeature::Color CellView::getColor() {
    return this->color;
}
