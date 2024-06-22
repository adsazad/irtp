#include <iostream>
#include "libs/Config.h"
#include "libs/Socket.h"
#include "Utils/DatabaseLoader.h"
// json
// #include <nlohmann/json.hpp>

int main() {
    Config config;
    config.load("../config.json");
    DatabaseLoader db;
    db.load(config);
    Socket socket;
    socket.InitializeSocket(config);

    
    return 0;
}