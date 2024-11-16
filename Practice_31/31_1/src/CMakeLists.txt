cmake_minimum_required(VERSION 3.23)


add_executable(31_1 main.cpp SmartPointer.cpp ${MY_INCLUDE_DIR}SmartPointer.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(31_1 PUBLIC ${MY_INCLUDE_DIR})