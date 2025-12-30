#Library Directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include"
                #"${CMAKE_BINARY_DIR}/include"
                 )
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src" 
               #"${CMAKE_BINARY_DIR}/src"
                )
#Code Examples
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples" 
                 #"${CMAKE_BINARY_DIR}/examples"
                )
#Tests Directory
set(TESTS_DIR "${CMAKE_SOURCE_DIR}/test" 
               #"${CMAKE_BINARY_DIR}/test"
                )


set(PROJECT_LANGUAGES "CXX") 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)


#GUI Vars

option(BUILD_EXAMPLES "Build Examples" ON)
option(BUILD_TESTS "Build Tests" ON)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)


message(STATUS "BUIDING FOR SHARED LIBS: ${BUILD_SHARED_LIBS}")
if(${BUILD_SHARED_LIBS})
   set(LIB_LINK_TYPE SHARED)
else()
   set(LIB_LINK_TYPE STATIC)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Windows")
endif()

