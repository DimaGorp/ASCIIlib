cmake_minimum_required(VERSION 4.2.0)
#Load Config Vars
include("cmake/ASKIIlibConfig.cmake")

message(STATUS "Building shared lib: ${BUILD_SHARED_LIBS}")
message(STATUS "Building examples: ${BUILD_EXAMPLES}")
message(STATUS "Building tests: ${BUILD_TESTS}")
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


#Build
if(${BUILD_EXAMPLES})
    #Examples
    add_subdirectory(${EXAMPLES_DIR})
elseif(${BUILD_TESTS})
    #Tests
    add_subdirectory(${TESTS_DIR})
endif()

#Make a library
add_library(${PROJECT_NAME} ${LIB_LINK_TYPE} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

