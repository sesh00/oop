#ifndef OOP_LOGGERGROUP_H
#define OOP_LOGGERGROUP_H

#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <utility>

class LoggerGroup{
public:
    virtual LoggerGroup &operator<<(const char * t) =0;
};

class FileLogger: public LoggerGroup{
public:
    explicit FileLogger(std::string fileName);
    ~FileLogger();
    FileLogger &operator<<(const char *t) override;
private:
    std::fstream ofs;
};


class ConsoleLogger: public LoggerGroup {
public:
    explicit ConsoleLogger(std::ostream* os_, std::pair<int, int> sizes_): os(os_),
    sizes(std::move(sizes_)) {}
    ~ConsoleLogger() = default;
    ConsoleLogger &operator<<(const char *t) override;
private:
    int cursorY = 2;
    std::ostream* os;
    std::pair<int, int> sizes;
};


#endif //OOP_LOGGERGROUP_H
