#ifndef DATABASE_LOADER_H
#define DATABASE_LOADER_H

#include <string>
#include <iostream>
#include "../libs/Config.h"

class DatabaseLoader {
    public:
    std::string connectionPath;
    DatabaseLoader();
    void load(Config& config);
    
};

#endif