cmake_minimum_required(VERSION 3.10)
project(shiny-enigma VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

set(SRC_LIST src/header.cpp)

add_executable(shiny-enigma src/driver.cpp ${SRC_LIST})

