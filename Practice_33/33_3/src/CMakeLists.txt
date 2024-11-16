cmake_minimum_required(VERSION 3.23)


add_executable(33_3 main.cpp List.cpp ${MY_INCLUDE_DIR}List.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(33_3 PUBLIC ${MY_INCLUDE_DIR})
