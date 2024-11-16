cmake_minimum_required(VERSION 3.23)

add_executable(28_2 main.cpp Train.cpp ${MY_INCLUDE_DIR}Train.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(28_2 PUBLIC ${MY_INCLUDE_DIR})