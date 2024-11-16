cmake_minimum_required(VERSION 3.23)

add_executable(31_2 main.cpp Person.cpp ${MY_INCLUDE_DIR}Person.h Graph.cpp ${MY_INCLUDE_DIR}Graph.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(31_2 PUBLIC ${MY_INCLUDE_DIR})