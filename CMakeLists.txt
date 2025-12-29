cmake_minimum_required(VERSION 4.2.0)

project(ASKIIlib
    #Choosen Language
    LANGUAGES CXX
    )

#Load Config Vars
include("cmake/ASKIIlibConfig.cmake")

#Build
if(${BUILD_EXAMPLES})
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()
