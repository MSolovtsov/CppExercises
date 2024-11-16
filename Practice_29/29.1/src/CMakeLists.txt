cmake_minimum_required(VERSION 3.23)

add_executable(29_1 main.cpp ${MY_INCLUDE_DIR}Talent.h Talent.cpp ${MY_INCLUDE_DIR}Dog.h Dog.cpp ${MY_INCLUDE_DIR}Nicknames.h Nicknames.cpp)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(29_1 PUBLIC ${MY_INCLUDE_DIR})
