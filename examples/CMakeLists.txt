#Various Examples
option(CONSOLE_APP "CLI Example" ON)
option(SFML_APP "Compatability with SFML" ON)
#Resource dir for showcase demonstration(sf::Image for Instance)
SET(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/resources)
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
