cmake_minimum_required(VERSION 4.2.0)

#Load Config Vars
include("cmake/ASKIIlibConfig.cmake")
#Check if we are Building in Source
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed")
endif()
project(ASKIIlib
    #Choosen Language
    LANGUAGES ${PROJECT_LANGUAGES}
    )

#Collect Sources
add_subdirectory(${SOURCE_DIR})

add_library(${PROJECT_NAME} ${LIB_LINK_TYPE} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_compile_definitions(${PROJECT_NAME} PRIVATE ASKII_EXPORTS)
#Build
if(${BUILD_EXAMPLES})
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()