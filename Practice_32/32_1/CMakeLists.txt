cmake_minimum_required(VERSION 3.23)
project(32_1)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

#[[include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)]]


add_executable(32_1 main.cpp)

target_link_libraries(32_1 PRIVATE nlohmann_json::nlohmann_json)