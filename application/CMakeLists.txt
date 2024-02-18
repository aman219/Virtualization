cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")

add_subdirectory("${CMAKE_SOURCE_DIR}/external/glfw" "external/glfw/build")
add_subdirectory("${CMAKE_SOURCE_DIR}/external/glad" "external/glad/build")

project(application)

include_directories("${CMAKE_SOURCE_DIR}/external/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/external/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/engine/include")
include_directories(include)

file(GLOB files "src/*.cpp")
add_executable(${PROJECT_NAME} ${files})

target_link_libraries(${PROJECT_NAME} PRIVATE engine glfw)