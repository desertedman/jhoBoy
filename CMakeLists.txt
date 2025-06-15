cmake_minimum_required(VERSION 3.10.0)
project(jhoBoy VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB SOURCES src/*.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(jhoBoy ${SOURCES})
