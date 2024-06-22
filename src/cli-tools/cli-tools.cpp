#include <iostream>
#include "../Utils/Common.cpp"
#include "../libs/Config.h"
#include "../Utils/DatabaseLoader.h"

int main()
{

    Config config;
    config.load("../config.json");

    DatabaseLoader dbloader;
    dbloader.load(config);

    std::cout << "ITPR CLI Tools" << std::endl;

    while (true)
    {
        std::cout << "Command available" << std::endl;
        std::cout << "Create Room: createroom" << std::endl;
        std::cout << "Exit: exit" << std::endl;
        std::string command;
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "createroom")
        {
            std::string name;
            std::cout << "Enter room name: ";
            std::cin >> name;
            dbloader.createRoom(name);
        }else if(command == "exit"){
            break;
        }
    }

    return 0;
}