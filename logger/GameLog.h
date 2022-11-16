#ifndef OOP_GAMELOG_H
#define OOP_GAMELOG_H

#include <string>
#include <utility>
#include <iostream>

enum Prefix{
    ERRORMESSAGE, GAMEMESSAGE, STATEMESSAGE, NONEMESSAGE
};

class Message{
public:
    Message(std::string pref_, std::string text_){
        text = pref_ + " " + text_ + "\n";
    }
     char* getMessage(){
         char *text_ = text.data();
         return text_;
    }
private:
    std::string text;
};

class GameLog {
public:
    virtual Message *execute(std::string text) = 0;
    explicit GameLog(Prefix pref_) : pref(pref_) {}
    virtual ~GameLog() = default;
protected:
    Prefix pref;
};

class ErrorMessage : public GameLog {
public:
    Message *execute(std::string text) override;
    ~ErrorMessage() override = default;
    ErrorMessage() : GameLog(ERRORMESSAGE) {}
};

class GameMessage : public GameLog {
public:
    Message *execute(std::string text) override;
    ~GameMessage() override = default;
    GameMessage() : GameLog(GAMEMESSAGE) {}
};

class StateMessage : public GameLog {
public:
    Message *execute(std::string text) override;
    ~StateMessage() override = default;
    StateMessage() : GameLog(STATEMESSAGE) {}
};

#endif //OOP_GAMELOG_H
