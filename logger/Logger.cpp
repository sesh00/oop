#include "Logger.h"

Logger &Logger::operator<<(Message *message) {
    for (auto & m_Stream : m_Streams){
        *m_Stream << message->getMessage();
    }
    return *this;
}

void Logger::attach(LoggerGroup *os) {
    m_Streams.push_back(os);
}

