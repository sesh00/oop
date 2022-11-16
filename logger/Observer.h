#pragma once
#ifndef OOP_OBSERVER_H
#define OOP_OBSERVER_H


#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <fstream>
#include "GameLog.h"
#include <map>

class Logger;
class IObserver {
public:
    virtual ~IObserver()= default;
    virtual void Update(Message* message_from_subject) = 0;
};

class ISubscriber {
public:
    virtual ~ISubscriber()= default;
    virtual void Subscribe(IObserver *observer) = 0;
    virtual void Unsubscribe(IObserver *observer) = 0;
    virtual void SendMessage() = 0;
};

class Subscriber : public ISubscriber {
public:
    ~Subscriber() override = default;
    void Subscribe(IObserver *observer) override;
    void Unsubscribe(IObserver *observer) override;
    static void detach(Prefix pref);
    static void attach(Prefix pref, GameLog* gameLog);
    void SendMessage() override {
        auto iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }
    void InitMessage(Prefix gameLog, std::string message = "");
    static std::map<Prefix, GameLog*> prefixMap;
protected:
    std::list<IObserver *> list_observer_;
    Message *message_;
};

class Observer: public IObserver {
public:
    explicit Observer(Subscriber &subject, Logger &logger);
    ~Observer() override = default;
    void Update(Message* message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();
private:
    Message *message_from_subject_;
    Subscriber &subject_;
    Logger &logger_;
};



#endif //OOP_OBSERVER_H
