#include "Event.h"
#include "Controller.h"

void Event::init(Controller* controller) {
    this->controller = controller;
    this->player = controller->player;
    this->field = controller->field;
}
