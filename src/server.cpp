#include <iostream>
#include "libs/Config.h"
#include "libs/Socket.h"
// json
// #include <nlohmann/json.hpp>

int main() {
    Config config;
    config.load("../config.json");
    Socket socket;
    socket.InitializeSocket(config);
    
    return 0;
}