#Library Directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include"
                "${CMAKE_BINARY_DIR}/include"
                 PARENT_SCOPE)
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src" 
               "${CMAKE_BINARY_DIR}/src"
                PARENT_SCOPE)
#Code Examples
set(EXAMPLES_DIR "${CMAKE_SOURCE_DIR}/examples" 
                "${CMAKE_BINARY_DIR}/examples"
                PARENT_SCOPE)
#Tests Directory
set(EXAMPLE_DIR "${CMAKE_SOURCE_DIR}/test" 
                "${CMAKE_BINARY_DIR}/test"
                PARENT_SCOPE)