cmake_minimum_required(VERSION 3.23)
project(33_Qt)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)

add_executable(33_Qt main.cpp)
target_link_libraries(Qt5::Widgets)
