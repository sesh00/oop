#include "LoggerGroup.h"
#include <windows.h>

ConsoleLogger &ConsoleLogger::operator<<(const char *t) {
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOUTPUT, {(SHORT)(sizes.first * 2), (SHORT)(++cursorY)});
    if (cursorY > sizes.second - 1){
        cursorY = 2;
        system("cls");
    }
    *os << t ;
    return *this;
}

FileLogger &FileLogger::operator<<(const char *t) {
    ofs.seekg(0, std::ios::end);
    std::string str = t;
    ofs << str;
    return *this;
}

FileLogger::FileLogger(std::string fileName) {
    ofs.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);

    if(!ofs.is_open()) {
        std::cout << "fileName: " << fileName <<  " failed to open! " << std::endl;
    }
}

FileLogger::~FileLogger(){
    ofs.close();
}