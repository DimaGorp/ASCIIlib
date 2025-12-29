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
                
#GUI Vars

option(BUILD_EXAMPLES "Build Examples")
option(BUILD_TESTS "Build Tests")

