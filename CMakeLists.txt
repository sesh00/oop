cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

include_directories(cell)
include_directories(event)
include_directories(field)
include_directories(control)
include_directories(player)
include_directories(utils)
include_directories(logger)

add_executable(
        OOP cell/Cell.cpp cell/Cell.h field/Field.cpp field/Field.h event/Event.cpp event/Event.h player/Player.cpp player/Player.h
        control/CommandReader.cpp control/CommandReader.h control/Mediator.cpp control/Mediator.h control/Controller.cpp
        control/Controller.h field/FieldView.cpp field/FieldView.h cell/CellView.cpp cell/CellView.h player/PlayAction.cpp
        player/PlayAction.h starter.cpp cell/CellFeature.cpp cell/CellFeature.h event/EnemyEventGroup.cpp event/EnemyEventGroup.h
        event/PropertiesEventGroup.cpp event/PropertiesEventGroup.h event/Factory.cpp event/Factory.h event/UtilEventGroup.cpp
        event/UtilEventGroup.h logger/Logger.cpp logger/Logger.h logger/LoggerGroup.cpp logger/LoggerGroup.h logger/Observer.cpp
        logger/Observer.h logger/GameLog.cpp logger/GameLog.h control/ControlCommand.cpp control/ControlCommand.h control/ControlConfig.cpp control/ControlConfig.h)



#g++ cell/Cell.cpp field/Field.cpp event/Event.cpp player/Player.cpp control/CommandReader.cpp control/Mediator.cpp control/Controller.cpp field/FieldView.cpp cell/CellView.cpp player/PlayAction.cpp starter.cpp
#add_executable(OOP utils/test1.cpp)