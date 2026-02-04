

#Download Dependencies
add_subdirectory(deps)


SET(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/resources)
#Make Config file
configure_file(Config.h.in ${CMAKE_BINARY_DIR}/examples/Config.h)


#Build Examples
add_subdirectory("ConsoleAppUsage")
add_subdirectory("SFML")
