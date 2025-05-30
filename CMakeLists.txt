cmake_minimum_required(VERSION 3.5)
project(lab08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./header)


add_executable(lab08
    ./src/main.cpp
    ./header/header.hpp
)
