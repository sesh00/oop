#include "GameLog.h"

Message *ErrorMessage::execute(std::string text) {
    return new Message("ERRORMESSAGE:", text);
}

Message *GameMessage::execute(std::string text) {
    return new Message("GAMEMESSAGE:", text);
}

Message *StateMessage::execute(std::string text) {
    return new Message("STATEMESSAGE:", text);
}
