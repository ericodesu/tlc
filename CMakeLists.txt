cmake_minimum_required(VERSION 3.20.3)

project(
    TLC
    VERSION 0.2
    LANGUAGES CXX
    DESCRIPTION "The Learning Channel for C++"
)

add_subdirectory(apps)
add_subdirectory(src)
add_subdirectory(tools)