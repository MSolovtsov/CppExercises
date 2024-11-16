cmake_minimum_required(VERSION 3.23)

add_executable(25_1 main.cpp
        ${MY_INCLUDE_DIR}/medical-instruments.h medical-procedures.cpp)

include_directories( ${MY_INCLUDE_DIR})

target_include_directories(25_1 PUBLIC ${MY_INCLUDE_DIR})