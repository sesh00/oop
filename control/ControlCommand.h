#ifndef OOP_CONTROLCOMMAND_H
#define OOP_CONTROLCOMMAND_H


#include <Observer.h>

class ControlCommand: public Subscriber {
    int actionIndex;
public:
    ControlCommand();
    bool setAction();
    int getAction();
};


#endif //OOP_CONTROLCOMMAND_H
