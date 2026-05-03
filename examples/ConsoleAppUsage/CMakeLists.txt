project(ConsoleAppUsage LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)
#Link library
target_link_libraries(${PROJECT_NAME} PRIVATE ASCIIlib::Core)
