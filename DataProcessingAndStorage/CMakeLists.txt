cmake_minimum_required(VERSION 3.29)
project(DataProcessingAndStorage)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataProcessingAndStorage main.cpp
        InMemoryDB.cpp
        InMemoryDB.h)
