cmake_minimum_required(VERSION 3.23)

add_executable(29_2 main.cpp Shape.cpp ${MY_INCLUDE_DIR}Shape.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(29_2 PUBLIC ${MY_INCLUDE_DIR})