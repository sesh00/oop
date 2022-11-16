#include "Observer.h"

#include <utility>
#include "Logger.h"

void Observer::PrintInfo() {
    logger_ << message_from_subject_;
}

void Observer::RemoveMeFromTheList() {
    subject_.Unsubscribe(this);
}

void Observer::Update(Message* message_from_subject) {
    this->message_from_subject_ = message_from_subject;
    PrintInfo();
}
Observer::Observer(Subscriber &subject, Logger &logger):
subject_(subject), logger_(logger){
    this->subject_.Subscribe(this);
}


void Subscriber::InitMessage(Prefix pref, std::string message) {
    if (prefixMap.find(pref) != prefixMap.end()) {
        GameLog* gl = prefixMap.at(pref);
        this->message_ = gl->execute(std::move(message));
        SendMessage();
    }
}

void Subscriber::Unsubscribe(IObserver *observer) {
    list_observer_.remove(observer);
}

void Subscriber::Subscribe(IObserver *observer) {
    list_observer_.push_back(observer);
}

std::map<Prefix, GameLog*> Subscriber::prefixMap = {};

void Subscriber::detach(Prefix pref) {
    prefixMap.erase(pref);
}

void Subscriber::attach(Prefix pref, GameLog* gameLog) {
    prefixMap[pref] = gameLog;
}






