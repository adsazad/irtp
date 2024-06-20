#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include "Config.h"
#include <netinet/in.h>


class Socket{
public:
    Config config;
    sockaddr_in serverAddress;
    int serverSocket;
    int clientSocket;

    Socket();
    void InitializeSocket(Config& config);
    void connect();
    void send(const std::string& message);
    std::string receive();
    void close();
};

#endif