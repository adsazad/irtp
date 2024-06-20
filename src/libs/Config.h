#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <nlohmann/json.hpp>

class Config{
    public:
        std::string host;
        int port;

        Config();

        void load(const std::string& path);
    
    private:
        void parseJson(const nlohmann::json& j);
};

#endif