cmake_minimum_required(VERSION 3.10)
project(irtp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "/Users/arashdeep/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_PREFIX_PATH "/Users/arashdeep/vcpkg/installed/x64-osx" CACHE STRING "" FORCE)


find_package(nlohmann_json CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)


# Add the executable
add_executable(server src/server.cpp src/libs/Config.cpp src/libs/Socket.cpp src/Utils/DatabaseLoader.cpp src/Utils/Common.cpp)
add_executable(cli-tools src/cli-tools/cli-tools.cpp src/libs/Config.cpp src/Utils/DatabaseLoader.cpp src/Utils/Common.cpp)
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(server PRIVATE $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>)
target_link_libraries(server PRIVATE $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>)
target_link_libraries(cli-tools PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(cli-tools PRIVATE $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>)
target_link_libraries(cli-tools PRIVATE $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>)
