#Set directory to where dependencies download
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/examples/deps)

include(FetchContent)
#if SFML not found - we must download it for convenience
if(NOT SFML_FOUND)
    message(STATUS "SFML not found - downloading dependency")
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW    TRUE
    )
    #Set options for SFML
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
else()
    message(STATUS "Found SFML version: ${SFML_VERSION}")
    message(STATUS "SFML include dir: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML libraries: ${SFML_LIBRARIES}")
endif()