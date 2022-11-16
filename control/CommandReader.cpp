#include "CommandReader.h"

std::istream& operator>>(std::istream& is, Prefix& prefix)
{
    std::string name;
    is >> name;
    if (name == "e")
        prefix = ERRORMESSAGE;
    else if (name == "g")
        prefix = GAMEMESSAGE;
    else if (name == "s")
        prefix = STATEMESSAGE;
    else
        prefix = NONEMESSAGE;
    return is;
}

void CommandReader::getUserCommand() {
    std::cout << "Enable console logger?\n";
    std::cin >> this->isConsoleLogger;

    std::cout << "Enable file logger?\n";
    std::cin >> this->isFileLogger;

    std::cout << "Which levels should be logged?\n" <<
    "s - state message, " << "g - game message\n" <<
    "e - error message, "<< "0 - no logging\n";

    for(auto & level : levels){
        std::cin >> level;
        if (getchar() == '\n') break;
    }

    std::cout << "Set field size?\n";
    int isSelected;
    std::cin >> isSelected;

    if (!isSelected) {
        this->fieldWidth = 25;
        this->fieldHeight = 25;
        return;
    }
    std::cout << "Width:";
    std::cin >> this->fieldWidth;

    std::cout << "Height:";
    std::cin >> this->fieldHeight;
}


std::pair<int,int> CommandReader::getFieldSize(){
    return {fieldWidth, fieldHeight};
};

std::pair<int,int> CommandReader::getLoggerProperties(){
    return {isConsoleLogger, isFileLogger};
};

Prefix* CommandReader::getLoggerLevels(){
    return levels;
};
