project(ConsoleAppUsage LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR}/examples)
#Link library
#target_link_libraries(${PROJECT_NAME} PRIVATE ASCIIlib::Image)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)