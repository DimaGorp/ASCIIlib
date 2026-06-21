project(SFMLExample LANGUAGES CXX)

add_executable(SFMLExample main.cpp)
#Link SFML
target_link_libraries(SFMLExample PRIVATE ASCIIlib::Image SFML::Graphics)

target_include_directories(SFMLExample PUBLIC ${INCLUDE_DIR} ${CMAKE_BINARY_DIR}/examples)
#if SFML was found or downloaded we create macro to use SFML constructions
if(SFML_FOUND)
    target_compile_definitions(SFMLExample PRIVATE SFML)
endif()