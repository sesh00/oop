#include <iostream>
#include <fstream>
#include <list>
#include <map>

class LoggerGroup{
public:
     virtual LoggerGroup &operator<<(const char * t) =0;
};

class FileLogger: public LoggerGroup{
public:
    explicit FileLogger(std::ofstream* ofs_): ofs(ofs_) {
        if (!ofs->is_open()) {
            throw std::runtime_error("file open failure");
        }
    }
    ~FileLogger() {
        ofs->close();
    }

    FileLogger &operator<<(const char *t) override {
        if(ofs->is_open()){
            try{
                *ofs << t;
            }catch(std::exception const& e){
                cout << "There was an error: " << e.what() << endl;
            }
        } else {
            throw std::runtime_error("file write failure");
        }
        return *this;
    }

private:
    std::ofstream* ofs;
};

class ConsoleLogger: public LoggerGroup {
public:
    explicit ConsoleLogger(std::ostream* os_): os(os_) {}

    ~ConsoleLogger() = default;

    ConsoleLogger &operator<<(const char *t) override {
        *os << t;
        return *this;
    }
private:
    std::ostream* os;
};


struct LoggingLevel{
    enum Level {
        TRACE, DEBUG, INFO, WARNING, ERROR, FATAL
    };
    std::map<Level, std::string> levelMap{
        {TRACE, "TRACE "},
        {DEBUG, "DEBUG "},
        {INFO, "INFO "},
        {WARNING, "WARNING "},
        {ERROR,"ERROR "},
        {FATAL, "FATAL "}
    };
    std::string getLevel(Level level){
        return levelMap[level];
    }
};

class Message{
public:
    Message(LoggingLevel::Level level_, std::string text_):
            level(level_), text(std::move(text_)) {
        text = loggingLevel.getLevel(level) + text;
    };
    char* getMessage(){
        char *text_ = text.data();
        return text_;
    }
private:
    std::string text;
    LoggingLevel loggingLevel;
    LoggingLevel::Level level;
};

class Logger {
    std::list<LoggerGroup*> m_Streams;

public:
    void attach(LoggerGroup *os) {
        m_Streams.push_back(os);
    }

    Logger &operator<<(Message message) {

        for (auto & m_Stream : m_Streams){
           *m_Stream << message.getMessage();
        }

        return *this;
    }
};


int main() {
    std::ofstream fOut(R"(C:\Users\sinne\CLionProjects\OOP\utils\log.txt)");
    Logger logger;

    logger.attach(new ConsoleLogger(&std::cout));
    logger.attach(new FileLogger(&fOut));
    logger.attach(new ConsoleLogger(&std::cerr));

    logger << Message(LoggingLevel::TRACE,"test1\n");
    logger << Message(LoggingLevel::DEBUG,"test2\n");
    logger << Message(LoggingLevel::INFO,"test3\n");
    logger << Message(LoggingLevel::WARNING,"test4\n");
    logger << Message(LoggingLevel::ERROR,"test5\n");
    logger << Message(LoggingLevel::FATAL,"test6\n");

}