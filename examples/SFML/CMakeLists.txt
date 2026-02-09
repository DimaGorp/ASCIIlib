project(SFML LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples/${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ASCIIlib SFML::Graphics)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} ${CMAKE_BINARY_DIR}/examples)