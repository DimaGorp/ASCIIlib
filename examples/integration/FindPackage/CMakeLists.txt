project(FindPackageExample LANGUAGES CXX)
add_executable(FindPackageExample main.cpp)

find_package(ASCIIlib REQUIRED)

target_link_libraries(FindPackageExample PUBLIC ASCIIlib::Core)