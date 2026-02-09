set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/examples/deps)
include(FetchContent)

find_package(SFML 3 QUIET COMPONENTS graphics)
if(NOT SFML_FOUND)
    message(STATUS "SFML not found - downloading dependency")
    FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    )
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
    set(SFML_FOUND TRUE PARENT_SCOPE)
else()
    message(STATUS "Found SFML version: ${SFML_VERSION}")
    message(STATUS "SFML include dir: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML libraries: ${SFML_LIBRARIES}")
endif()