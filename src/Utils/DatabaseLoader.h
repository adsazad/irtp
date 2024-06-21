#ifndef DATABASE_LOADER_H
#define DATABASE_LOADER_H

#include <string>
#include <iostream>

class DatabaseLoader {
    public:
    DatabaseLoader();
    void load(const std::string& path);
    
};

#endif