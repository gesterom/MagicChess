cmake_minimum_required (VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (server VERSION 0.0.1 )
include_directories("./include")
file(GLOB SOURCES ./src/*.cpp ./src/Repository/*.cpp)

add_executable(server ./main.cpp ${SOURCES})
