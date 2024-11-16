cmake_minimum_required(VERSION 3.23)


add_executable(33_2 main.cpp Game.cpp ${MY_INCLUDE_DIR}Game.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(33_2 PUBLIC ${MY_INCLUDE_DIR})