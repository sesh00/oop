#include "ControlConfig.h"

void ControlConfig::setDefault() {
    isRed = true;
    InitMessage(ERRORMESSAGE,"Default commands is set");
    for (auto& pair : config)
    {
        pair.second = std::make_pair(defaultConfig.at(pair.first), pair.second.second);
    }
}

void ControlConfig::checkConfig() {
    for (auto& pair : config)
    {
        if(!pair.second.first){
            setDefault();
            break;
        }
    }
}

std::istream& operator>>(std::istream& is, ActionPrefix& actionPrefix)
{
    std::string move;
    is >> move;
    if (move == "UP")
        actionPrefix = UP;
    else if (move == "DOWN")
        actionPrefix = DOWN;
    else if (move == "LEFT")
        actionPrefix = LEFT;
    else if (move == "RIGHT")
        actionPrefix = RIGHT;
    else if (move == "TP")
        actionPrefix = TP;
    else
        actionPrefix = NONE;
    return is;
}

FileConfig::FileConfig(const std::string& filename) {
    file.open(filename, std::ios_base::in);
}

bool FileConfig::inConfig(int key) {
    for(int uk : usedKeys)
        if(uk == key) return false;
    return true;
}

ActionMap FileConfig::initConfig() {
    if (isRed) return config;
    if(!file.is_open()){
        setDefault();
        InitMessage(ERRORMESSAGE,"1");
        return config;
    }
    std::string line;
    ActionPrefix prefix;
    int key = 0;
    while (getline(file, line ))
    {
        std::stringstream stream(line);
        stream >> prefix >> std::hex>> key;

        if(config.count(prefix) == 0){
            setDefault();
            InitMessage(ERRORMESSAGE,"Such command prefix does not exists");
            break;
        }

        if(key == '\0'){
            setDefault();
            InitMessage(ERRORMESSAGE,"Key was not set for all commands");
            break;
        }

        if(!inConfig(key)) {
            setDefault();
            InitMessage(ERRORMESSAGE,"This key already in use");
            break;
        }

        usedKeys.push_back(key);

        if(!config.at(prefix).first) {
            config.at(prefix).first = key;
        } else {
            InitMessage(ERRORMESSAGE,"Two or more prefixes in file");
            setDefault();
            break;
        }
    }
    checkConfig();
    isRed = true;
    return config;
}

FileConfig::~FileConfig() {
    file.close();
}