#ifndef DATABASE_LOADER_H
#define DATABASE_LOADER_H

#include <string>
#include <iostream>
#include "../libs/Config.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>


class DatabaseLoader {
    public:
    std::string connectionPath;
    mongocxx::database db;
    DatabaseLoader();
    void load(Config& config);
    
};

#endif