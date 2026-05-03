#Set Runtime output directory for Examples
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples/${PROJECT_NAME})
#Various Examples
option(CONSOLE_APP "CLI Example" ON)
option(SFML_APP "Compatability with SFML" ON)
# if it is an Example
# that uses SFML we must download it
# or find it at first place
if(SFML_APP)
    #Firstly, try to find it
    find_package(SFML 3 COMPONENTS Graphics)
    if(NOT SFML_FOUND)
        #Download SFML as a dependency
        add_subdirectory(deps)
    endif()
    #Resource dir for showcase demonstration(sf::Image for Instance)
    SET(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/resources)
    #Make Config file
    configure_file(Config.h.in ${CMAKE_BINARY_DIR}/examples/Config.h)
endif()

if(CONSOLE_APP)
    #Build Console Version
    add_subdirectory("ConsoleAppUsage")
endif()

#Compatibility with graphical libraries
if(SFML_APP)
    #SFML
    add_subdirectory("SFML")
endif()
