cmake_minimum_required(VERSION 4.2.0)

#Load Config Vars
include("cmake/ASKIIlibConfig.cmake")


project(ASKIIlib
    #Choosen Language
    LANGUAGES ${PROJECT_LANGUAGES}
    )

#Combine headers and Sources
add_subdirectory(${INCLUDE_DIR})
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