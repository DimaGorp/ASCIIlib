
option(CONSOLE_APP "CLI Example" ON)
option(SFML_APP "Compatability with SFML" ON)
if(SFML_APP)
    #Download SFML Dependencies
    find_package(SFML 3 COMPONENTS Graphics)
    if(NOT SFML_FOUND)
        add_subdirectory(deps)
    endif()
    SET(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/resources)
    #Make Config file
    configure_file(Config.h.in ${CMAKE_BINARY_DIR}/examples/Config.h)
endif()

if(CONSOLE_APP)
    #Build Examples
    add_subdirectory("ConsoleAppUsage")
endif()
if(SFML_APP)
    add_subdirectory("SFML")
endif()
