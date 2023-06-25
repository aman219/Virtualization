cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)

project(Virtualization)

add_subdirectory(glfw)
add_subdirectory(Engine)

include_directories(glfw/include)
include_directories(glad/include)
include_directories(Application/include)

add_executable(${PROJECT_NAME} Application/src/main.cpp 
                               Application/src/glad.c
                               Application/src/render.cpp
                               )

target_link_directories(${PROJECT_NAME} 
    PRIVATE build/glfw/src
    PRIVATE build/Engine
    )

target_link_libraries(${PROJECT_NAME} glfw3 engine)