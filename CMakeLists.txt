cmake_minimum_required(VERSION 3.10)
project(irtp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "/Users/arashdeep/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_PREFIX_PATH "/Users/arashdeep/vcpkg/installed/x64-osx" CACHE STRING "" FORCE)


find_package(nlohmann_json CONFIG REQUIRED)

# Add the executable
add_executable(server src/server.cpp src/libs/Config.cpp)
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)
