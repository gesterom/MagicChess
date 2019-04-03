cmake_minimum_required (VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (game)
include_directories("./include")
file(GLOB SOURCES ./src/*.cpp)

add_executable(game main.cpp ${SOURCES})
