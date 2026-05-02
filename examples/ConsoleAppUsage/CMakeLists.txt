cmake_minimum_required(VERSION 3.28.2[...4.2.0])
project(ConsoleAppUsage LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples/${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ASCIIlib)
