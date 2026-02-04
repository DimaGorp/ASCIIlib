project(ConsoleApp LANGUAGES ${PROJECT_LANGUAGES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ASKIIlib)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
