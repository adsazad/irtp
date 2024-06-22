#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
    public:
        int id;
        std::string name;

        Room();
        Room(std::string name, int id);
};

#endif