#Various Examples
option(CONSOLE_APP "CLI Example" ON)
option(SFML_APP "Compatability with SFML" ON)
# if it is an Example
# that uses SFML we must download it
# or find it at first place
if(SFML_APP)
    #Firstly, try to find it, if we can't then download
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW    TRUE
        FIND_PACKAGE_ARGS 3 COMPONENTS Graphics
    )
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
    set_target_properties(sfml-graphics sfml-window sfml-system PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(SFML_FOUND TRUE CACHE BOOL "SFML found or fetched" FORCE)
    
    #Resource dir for showcase demonstration(sf::Image for Instance)
    SET(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/resources)
endif()
#Make Config file
configure_file(Config.h.in ${CMAKE_BINARY_DIR}/examples/Config.h)
if(CONSOLE_APP)
    #Build Console Version
    add_subdirectory("ConsoleAppUsage")
endif()

#Compatibility with graphical libraries
if(SFML_APP)
    #SFML
    add_subdirectory("SFML")
endif()
