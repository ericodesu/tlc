cmake_minimum_required(VERSION 3.20.3)
project(
    TLC
    VERSION 0.1
    LANGUAGES CXX
    DESCRIPTION "The Learning Channel for C++")

include(FetchContent)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)

add_subdirectory(lib)
add_subdirectory(src)