cmake_minimum_required(VERSION 3.10)
project(boop)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_compile_options(-Wall -Wextra -Werror)

find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)
set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp) 
add_library(objects_files OBJECT ${SOURCE_FILES})
add_executable(${PROJECT_NAME} main.cpp $<TARGET_OBJECTS:objects_files>) 

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
