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
option(BUILD_EXAMPLES "Build Examples" ON)
option(BUILD_TESTS "Build Tests" ON)

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
project(ASCIIlib LANGUAGES CXX)

#Collect Sources
add_subdirectory(${SOURCE_DIR})

#Build
if(${BUILD_EXAMPLES})
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()

#Make a library
add_library(${PROJECT_NAME} ${SOURCES})
#Create an alias for the library
add_library(ASCII::ASCIIlib ALIAS ${PROJECT_NAME})

#Set properties for Target
set_target_properties(${PROJECT_NAME}
                        PROPERTIES
                        CMAKE_CXX_STANDARD 20
                        CMAKE_CXX_STANDARD_REQUIRED ON
                        CMAKE_CXX_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME} PRIVATE 
                    "$<BUILD_INTERFACE:${INCLUDE_DIR}>"
                    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
                    )
#install library
include(GNUInstallDirs) 

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT ${PROJECT_NAME}-targets
        FILE ${PROJECT_NAME}-targets.cmake
        NAMESPACE ASCII::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

