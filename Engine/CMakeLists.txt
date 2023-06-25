cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)

project(engine)

include_directories(include)
include_directories(../glad/include)

add_library(${PROJECT_NAME} STATIC src/engine.cpp src/glad.c)