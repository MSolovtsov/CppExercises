cmake_minimum_required(VERSION 3.23)


add_executable(33_1 main.cpp
        Store.cpp ShoppingCart.cpp
        ${MY_INCLUDE_DIR}Store.h ${MY_INCLUDE_DIR}ShoppingCart.h)

include_directories(${MY_INCLUDE_DIR})

target_include_directories(33_1 PUBLIC ${MY_INCLUDE_DIR})