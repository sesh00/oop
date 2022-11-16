#ifndef OOP_CONTROLCONFIG_H
#define OOP_CONTROLCONFIG_H

#include "../player/PlayAction.h"
#include <map>
#include <string>
#include <sstream>

enum ActionPrefix{
    UP, DOWN, LEFT, RIGHT, NONE, TP
};

typedef std::map<ActionPrefix, std::pair<int, PlayAction*>> ActionMap;

class ControlConfig: public Subscriber{
protected:

    std::map<ActionPrefix, int> defaultConfig{
            {UP, 0x26},
            {DOWN, 0x28},
            {LEFT, 0x25},
            {RIGHT, 0x27},
            {NONE, -1},
            {TP, -2}
    };

    ActionMap config{
            {UP, {{},new MoveUpAction}},
            {DOWN, {{},new MoveDownAction}},
            {LEFT, {{},new MoveLeftAction}},
            {RIGHT, {{},new MoveRightAction}},
            {NONE, {{},new NoneAction}},
            {TP, {{},new TpAction}},
    };

    void setDefault();
    void checkConfig();
public:
    virtual ActionMap getConfig() = 0;
    ~ControlConfig() override = default;
};

class FileConfig : public ControlConfig{
private:
    std::fstream file;
    std::vector<int> usedKeys = {};
    bool inConfig(int key);
public:
    explicit FileConfig(const std::string& filename);
    ActionMap getConfig() override ;
    ~FileConfig() override;
};

#endif //OOP_CONTROLCONFIG_H
