#include <iostream>
#include "DatabaseLoader.h"
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include "Common.cpp"

mongocxx::instance instance{};  // Ensure this instance persists for the entire duration of your program

DatabaseLoader::DatabaseLoader() {
    std::cout << "DatabaseLoader created" << std::endl;
}

void DatabaseLoader::load(Config &config) {
    std::cout << "Loading database from " << config.mongoHost << std::endl;
    this->connectionPath = "mongodb://" + config.mongoHost + ":" + std::to_string(config.mongoPort) + "/" + config.mongoDatabase;
    std::cout << "Connection path: " << this->connectionPath << std::endl;
    
    try {
        const auto uri = mongocxx::uri{this->connectionPath};

        // Set the version of the Stable API on the client.
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);

        // Create the client
        this->client = mongocxx::client{uri, client_options};
        std::cout << "Connected to database" << std::endl;
        this->db = client[config.mongoDatabase];
        
        // Check if database exists
        auto collections = db.list_collections();
        bool db_exists = false;
        for (auto &&coll : collections) {   
            db_exists = true;
            break;
        }

        // If the database doesn't exist, create it by adding a dummy collection
        if (!db_exists) {
            std::cout << "Database does not exist. Creating the database by adding a dummy collection." << std::endl;
            db["room"].insert_one(bsoncxx::builder::stream::document{} << "dummy" << 1 << bsoncxx::builder::stream::finalize);
            db["room"].drop();
        } else {
            std::cout << "Database already exists." << std::endl;
        }

        std::cout << "Database loaded" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error connecting to database: " << e.what() << std::endl;
        throw;
    }
}

void DatabaseLoader::createRoom(std::string roomName) {
    std::string randomId = genRand(10);
    auto res = db["room"].find_one(bsoncxx::builder::stream::document{} << "id" << randomId << bsoncxx::builder::stream::finalize);
    while (res) {
        randomId = genRand(10);
        res = db["room"].find_one(bsoncxx::builder::stream::document{} << "id" << randomId << bsoncxx::builder::stream::finalize);
    }
    std::cout << "Room ID: " << randomId << std::endl;
    // Insert the new room into the database
    bsoncxx::builder::stream::document document{};
    document << "id" << randomId << "name" << roomName;
    db["room"].insert_one(document.view());
    std::cout << "Room created" << std::endl;
}
