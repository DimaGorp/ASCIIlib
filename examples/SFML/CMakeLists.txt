project(SFML LANGUAGES ${PROJECT_LANGUAGES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ASKIIlib SFML::Graphics)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} ${CMAKE_BINARY_DIR}/examples)