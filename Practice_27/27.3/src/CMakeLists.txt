cmake_minimum_required(VERSION 3.23)

add_executable(27_3 main.cpp Head_of_the_company.cpp ${MY_INCLUDE_DIR}Head_of_the_company.h Worker.cpp ${MY_INCLUDE_DIR}Worker.h Manager.cpp ${MY_INCLUDE_DIR}Manager.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(27_3 PUBLIC ${MY_INCLUDE_DIR})