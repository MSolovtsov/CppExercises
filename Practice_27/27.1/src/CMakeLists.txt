cmake_minimum_required(VERSION 3.23)


add_executable(27_1 main.cpp Branch.cpp ${MY_INCLUDE_DIR}Branch.h LargeBranch.cpp ${MY_INCLUDE_DIR}LargeBranch.h ElfesNames.cpp ${MY_INCLUDE_DIR}ElfesNames.h Tree.cpp ${MY_INCLUDE_DIR}Tree.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(27_1 PUBLIC ${MY_INCLUDE_DIR})