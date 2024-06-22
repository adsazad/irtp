#include <iostream>
#include "DatabaseLoader.h"
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>


DatabaseLoader::DatabaseLoader(){
    std::cout << "DatabaseLoader created" << std::endl;
    
}

void DatabaseLoader::load(Config& config){
    // config.mongoHost;
    // config.mongoPort;
    // config.mongoDatabase;
    std::cout << "Loading database from " << config.mongoHost << std::endl;
    this->connectionPath = "mongodb://" + config.mongoHost + ":" + std::to_string(config.mongoPort);
    std::cout << "Connection path: " << this->connectionPath << std::endl;
    mongocxx::instance inst{};
    const auto uri = mongocxx::uri{this->connectionPath};

    // Set the version of the Stable API on the client.
    mongocxx::options::client client_options;
    const auto api = mongocxx::options::server_api{ mongocxx::options::server_api::version::k_version_1 };
    client_options.server_api_opts(api);

    // Create the client
    mongocxx::client client{uri, client_options};
    std::cout << "Connected to database" << std::endl;
    mongocxx::database db = client[config.mongoDatabase];
    std::cout << "Database loaded" << std::endl;

}