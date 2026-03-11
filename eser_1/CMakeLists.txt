cmake_minimum_required(VERSION 3.20)
project(esercizio1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall")

add_executable(esercizio1 esercizio1.cpp)