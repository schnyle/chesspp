cmake_minimum_required(VERSION 3.28)
project(chess VERSION 2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")

add_compile_options(-Wall -Wextra)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} 
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_compile_definitions(${PROJECT_NAME}
  PRIVATE
  SOURCE_DIR_PATH="${SOURCE_DIR_PATH}"
)