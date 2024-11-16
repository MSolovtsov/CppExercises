cmake_minimum_required(VERSION 3.23)
project(33_boost)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(33_boost main.cpp)
target_link_libraries(33_boost ${Boost_LIBRARIES})

if (MINGW)
    target_link_libraries(33_boost ws2_32)
endif()