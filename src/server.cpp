#include <iostream>
#include "libs/Config.h"
#include "libs/Socket.h"
#include "Utils/DatabaseLoader.h"
// json
// #include <nlohmann/json.hpp>

int main() {
    Config config;
    config.load("../config.json");
    DatabaseLoader dbloader;
    dbloader.load(config);
    // create mongodb collection
    // dbloader.db.createCollection("users");
    Socket socket;
    socket.InitializeSocket(config);

    
    return 0;
}