#include <iostream>
#include "libs/Config.h"
// json
// #include <nlohmann/json.hpp>

int main() {
    Config config;
    config.load("../config.json");
    std::cout << "Host: " << config.host << std::endl;
    return 0;
}