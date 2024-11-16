cmake_minimum_required(VERSION 3.23)
project(30_1)

set(CMAKE_CXX_STANDARD 17)

# ================== ПЕРВЫЙ СПОСОБ ==================
#
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
# ========== 1.10 = 17 ==============
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(30_1 main.cpp)

target_link_libraries(30_1 PRIVATE cpr::cpr)