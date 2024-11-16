cmake_minimum_required(VERSION 3.23)

add_executable(28_1 main.cpp Swimmer.cpp ${MY_INCLUDE_DIR}Swimmer.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(28_1 PUBLIC ${MY_INCLUDE_DIR})