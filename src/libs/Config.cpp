#include "Config.h"
#include <fstream>
#include <stdexcept>

Config::Config() : host("localhost"), port(8080) {}

void Config::load(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + path);
    }
    
    nlohmann::json j;
    file >> j;
    parseJson(j);

    file.close();
    

}

void Config::parseJson(const nlohmann::json& j) {
    host = j.at("host").get<std::string>();
    port = j.at("port").get<int>();
    mongoHost = j.at("mongo").at("host").get<std::string>();
    mongoPort = j.at("mongo").at("port").get<int>();
    mongoDatabase = j.at("mongo").at("database").get<std::string>();
    
}