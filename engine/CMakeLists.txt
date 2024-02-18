cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/application/lib")

project(engine)

include_directories("${CMAKE_SOURCE_DIR}/external/glad/include")
include_directories("include")

add_library(${PROJECT_NAME} STATIC src/engine.cpp ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} GL)