cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)

project(engine)

add_library(${PROJECT_NAME} STATIC src/main.cpp)