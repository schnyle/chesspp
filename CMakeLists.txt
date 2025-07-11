cmake_minimum_required(VERSION 3.28)
project(chess VERSION 2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

set(SOURCES src/main.cpp)

add_executable(chess ${SOURCES})
target_include_directories(chess PRIVATE src)

