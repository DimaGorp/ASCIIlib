cmake_minimum_required(VERSION 3.28.2[...4.2.0])

#Library Directories
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
#Code Examples
set(EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")
#Tests Directory
set(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
#Disable in Source Build
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
#Build Shared libs
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
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
            VERSION 0.0.1
            LANGUAGES CXX
        )


#Build externals
if(${BUILD_EXAMPLES})
    message(STATUS "Building examples...")
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    message(STATUS "Building tests...")
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()

#Collect Sources and make a library components
add_subdirectory(${INCLUDE_DIR})
add_subdirectory(${SOURCE_DIR})

#Path's for Installing
include(GNUInstallDirs)

# Specify Install rules for Library

# Copy Library to install destination
install(TARGETS Core
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INLUDEDIR}
        )

# Copy Header Files to install destination
install(DIRECTORY ${INCLUDE_DIR}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.hpp"
        )
#[[==
#Export and Create Config file
install(EXPORT ${PROJECT_NAME}Targets 
        FILE ASCIIlibConfig.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}/cmake
        NAMESPACE ASCII::
)
#==]]


#Create Config for Finding Library via find_package()
include(CMakePackageConfigHelpers)
