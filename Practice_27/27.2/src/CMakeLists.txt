cmake_minimum_required(VERSION 3.23)

add_executable(27_2 main.cpp ${MY_INCLUDE_DIR}/GeometricFigure.h Circle.cpp ${MY_INCLUDE_DIR}/Circle.h Square.cpp ${MY_INCLUDE_DIR}/Square.h Rectangle.cpp ${MY_INCLUDE_DIR}/Rectangle.h GeometricFigure.cpp Triangle.cpp ${MY_INCLUDE_DIR}/Triangle.h)

include_directories( ${MY_INCLUDE_DIR})

target_include_directories(27_2 PUBLIC ${MY_INCLUDE_DIR})