#include "UtilEventGroup.h"
#include "Controller.h"
void PortalActivatedEvent::emitEvent() {
    controller->setState(Controller::Win);
}
