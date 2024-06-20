
#include <iostream>
#include "Socket.h"
#include <sys/socket.h>


Socket::Socket(){
    std::cout << "Socket created" << std::endl;
}

void Socket::InitializeSocket(Config& config){
    std::cout << "Socket Configure Load" << std::endl;
    // host
    std::cout << "Host: " << config.host << std::endl;
    this->config = config;
    connect();
}

void Socket::connect(){
    std::cout << "Connecting to Socket" << std::endl;
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Server Socket: " << this->serverSocket << std::endl;

    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(config.port);
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;
    std::cout << "Server Address: " << serverAddress.sin_addr.s_addr << std::endl;
    
    if(bind(this->serverSocket, (struct sockaddr*)&serverAddress, sizeof(this->serverAddress)) < 0){
        std::cout << "Error binding socket" << std::endl;
    }
    std::cout << "Socket connected" << std::endl;
    listen(this->serverSocket, 3);

    this->clientSocket = accept(this->serverSocket, (struct sockaddr*)&serverAddress, (socklen_t*)&serverAddress);
    std::cout << "Client Socket: " << this->clientSocket << std::endl;

}


