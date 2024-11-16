cmake_minimum_required(VERSION 3.23)

add_executable(25_2 main.cpp ${MY_INCLUDE_DIR}/cpu.h ${MY_INCLUDE_DIR}/ram.h ${MY_INCLUDE_DIR}/disk.h ${MY_INCLUDE_DIR}/gpu.h ${MY_INCLUDE_DIR}/kbd.h
        ram.cpp disk.cpp cpu.cpp gpu.cpp kbd.cpp)
target_include_directories(25_2 PUBLIC ${MY_INCLUDE_DIR})