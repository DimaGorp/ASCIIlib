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

#Language Standart
set(PROJECT_LANGUAGES "CXX") 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#Disable Compiler Standart and Use only C++ Standart
set(CMAKE_CXX_EXTENSIONS OFF)
#Disable in Source Build
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
#options for Building externals 
option(BUILD_EXAMPLES "Build Examples" ON)
option(BUILD_TESTS "Build Tests" ON)

#Choosing link type for library
if(${BUILD_SHARED_LIBS})
   set(LIB_LINK_TYPE SHARED)
else()
   set(LIB_LINK_TYPE STATIC)
endif()

#Cross-Platform Stuff
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Windows")
endif()

