#include <Logger.h>
#include "control/CommandReader.h"
#include "control/Controller.h"
#include "control/Mediator.h"

int main() {
    CommandReader commandReader;
    commandReader.getUserCommand();

    auto sizes  = commandReader.getFieldSize();
    auto logProperties  = commandReader.getLoggerProperties();
    auto logLevels = commandReader.getLoggerLevels();

    Logger logger;
    if (logProperties.first)
        logger.attach(new ConsoleLogger(&std::cerr, sizes));

    if(logProperties.second)
        logger.attach(new FileLogger(R"(C:\Users\sinne\CLionProjects\OOP\logger\log.txt)"));

    Controller controller(&logger, logLevels, sizes.first, sizes.second);
    Mediator mediator(&controller, &commandReader);
    mediator.startGame();

}