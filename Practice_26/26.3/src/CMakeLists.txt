cmake_minimum_required(VERSION 3.23)


add_executable(26_3 main.cpp ${MY_INCLUDE_DIR}/window.h Window.cpp)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(26_3 PUBLIC ${MY_INCLUDE_DIR})