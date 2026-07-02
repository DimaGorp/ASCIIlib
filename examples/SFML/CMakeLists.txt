project(SFMLExample LANGUAGES CXX)

#Firstly, try to find it, if we can't then download
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS 3 COMPONENTS Graphics
)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SFML)
if (NOT SFML_FOUND AND TARGET sfml-graphics)
    set_target_properties(sfml-graphics sfml-window sfml-system PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

add_executable(SFMLExample main.cpp)
#Link SFML
target_link_libraries(SFMLExample PRIVATE ASCIIlib::ImageGenerator ASCIIlib::ImageAdaptors SFML::Graphics)

target_include_directories(SFMLExample PUBLIC ${INCLUDE_DIR} ${CMAKE_BINARY_DIR}/examples)
#if SFML was found or downloaded we create macro to use SFML constructions
target_compile_definitions(SFMLExample PRIVATE SFML)
