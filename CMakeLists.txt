cmake_minimum_required(VERSION 3.28.2[...4.2.0])

#Library Directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
#Code Examples
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples")
#Tests Directory
set(TESTS_DIR "${CMAKE_SOURCE_DIR}/test")

#Disable in Source Build
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
#options for Building externals 
option(BUILD_EXAMPLES "Build Examples" OFF)
option(BUILD_TESTS "Build Tests" OFF)

message(STATUS "Building shared lib: ${BUILD_SHARED_LIBS}")
message(STATUS "Building examples: ${BUILD_EXAMPLES}")
message(STATUS "Building tests: ${BUILD_TESTS}")
#Check if we are Building in Source
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed")
endif()

#Set up Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release
        CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
#Set the project name and languages
project(ASCIIlib 
            VERSION 1.0.0
            LANGUAGES CXX
        )


#Build
if(${BUILD_EXAMPLES})
    message(STATUS "Building examples...")
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    message(STATUS "Building tests...")
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()

#Collect Sources and make a library and its components
add_subdirectory(${INCLUDE_DIR})
add_subdirectory(${SOURCE_DIR})

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE Core)
#Set properties for Target
set_target_properties(${PROJECT_NAME}
                        PROPERTIES
                        CMAKE_CXX_STANDARD 20
                        CMAKE_CXX_STANDARD_REQUIRED ON
                        CMAKE_CXX_EXTENSIONS OFF
)

# Exporting a library
include(GNUInstallDirs)

# Add library for exporting
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        )
#Export a library
install(EXPORT ${PROJECT_NAME} 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        NAMESPACE ASCII::
)
#Export an ASCIIlibConfig.cmake file
install(FILES ${PROJECT_SOURCE_DIR}/cmake/ASCIIlibConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

