#pragma once
#ifndef OOP_CELLFEATURE_H
#define OOP_CELLFEATURE_H

#include <iostream>
#include <utility>
#include <windows.h>
#include <Factory.h>

class CellFeature {
public:
    enum Color
    {
        Black       = 0,
        Default     = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        Grey        = FOREGROUND_INTENSITY,
        White       = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Blue        = FOREGROUND_BLUE,
        Green       = FOREGROUND_GREEN,
        Cyan        = FOREGROUND_GREEN | FOREGROUND_BLUE,
        Red         = FOREGROUND_RED | FOREGROUND_INTENSITY,
        Purple      = FOREGROUND_RED   | FOREGROUND_BLUE,
        LightBlue   = FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
        LightGreen  = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        LightCyan   = FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
        LightRed    = FOREGROUND_RED   | FOREGROUND_INTENSITY,
        LightPurple = FOREGROUND_RED   | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
        Orange      = FOREGROUND_RED   | FOREGROUND_GREEN,
        Yellow      = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    };


    explicit CellFeature(std::string _view, Color _color) : view(std::move(_view)), color(_color) {}
    inline std::string getView() { return view; }
    inline Color getColor() { return color; }
    virtual Event * execute() = 0;
    virtual ~CellFeature() = default;
protected:
    std::string view;
    Color color;

    AbstractFactory* const enemyFactory = new EnemyFactory;
    AbstractFactory* const utilFactory = new UtilFactory;
    AbstractFactory* const propertyFactory = new PropertyFactory;
};

class HealFeature : public CellFeature {
public:
    Event * execute() override;
    ~HealFeature() override = default;
    HealFeature() : CellFeature("\3",LightRed) {}
};

class EnemyFeature : public CellFeature {
public:
    Event * execute() override;
    ~EnemyFeature() override = default;
    EnemyFeature() : CellFeature("*", LightBlue) {}
};

class EmptyFeature : public CellFeature {
public:
    Event * execute() override;
    ~EmptyFeature() override = default;
    EmptyFeature() : CellFeature(".",White) {}
};

class WallFeature : public CellFeature {
public:
    Event * execute() override;
    ~WallFeature() override = default;
    WallFeature() : CellFeature("0", White) {}
};

class PlayerFeature : public CellFeature {
public:
    Event * execute() override;
    ~PlayerFeature() override = default;
    PlayerFeature() : CellFeature("\2",Yellow) {}
};

class CoinFeature : public CellFeature {
public:
    Event * execute() override;
    ~CoinFeature() override = default;
    CoinFeature() : CellFeature("$", LightGreen) {}
};

class TrapFeature : public CellFeature {
public:
    Event * execute() override;
    ~TrapFeature() override = default;
    TrapFeature() : CellFeature(".",White ) {}
};

class TeleportFeature : public CellFeature {
public:
    Event * execute() override;
    ~TeleportFeature() override = default;
    TeleportFeature() : CellFeature("@", LightPurple) {}
};

class PortalFeature : public CellFeature {
public:
    Event * execute() override;
    ~PortalFeature() override = default;
    PortalFeature() : CellFeature("@", LightPurple) {}
};


#endif //OOP_CELLFEATURE_H
