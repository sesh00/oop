#pragma once
#ifndef OOP_PLAYACTION_H
#define OOP_PLAYACTION_H


#include "Player.h"
#include "../field/Field.h"
#include "../field/FieldView.h"

class PlayAction {
public:
    virtual void action() = 0;
    void init(Player* player, Field* field);
    virtual ~PlayAction() = default;

    Player * player;
    Field * field;

};

class NoneAction: public PlayAction{
public:
    void action() override;
    ~NoneAction() override = default;
};

class MoveLeftAction: public PlayAction{
public:
    void action() override;
    ~MoveLeftAction() override = default;

};
class MoveRightAction: public PlayAction{
public:
    void action() override;
    ~MoveRightAction() override = default;
};
class MoveUpAction: public PlayAction{
public:
    void action() override;
    ~MoveUpAction() override = default;
};
class MoveDownAction: public PlayAction{
public:
    void action() override;
    ~MoveDownAction() override = default;
};

class TpAction: public PlayAction{
public:
    void action() override;
    ~TpAction() override = default;
};

#endif //OOP_PLAYACTION_H
