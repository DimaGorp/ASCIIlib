option(ADAPTERS_LIBRARY "Library of Adapters" OFF)
cmake_dependent_option(SFML_ADAPTER "SFML Library Image Adapter" OFF "ADAPTERS_LIBRARY" OFF)
cmake_dependent_option(SDL_ADAPTER "SDL Library Image Adapter" OFF "ADAPTERS_LIBRARY" OFF)




#Core Component
add_library(img-generator)

# Use different directories
# for include cause it differs
# when building and installing
target_include_directories(
        img-generator
    PUBLIC
        #Use that directory if we are Building library
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        #Use that directory if we are installing library
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${INCLUDE_DIR}/Interfaces>
    PRIVATE
        $<BUILD_INTERFACE:${INCLUDE_DIR}/Core>
)

add_library(${PROJECT_NAME}::ImageGenerator ALIAS img-generator)


if(ADAPTERS_LIBRARY)
    add_library(img-adapters)
    target_include_directories(
            img-adapters
        PUBLIC
            #Use that directory if we are Building library
            $<BUILD_INTERFACE:${INCLUDE_DIR}>
            #Use that directory if we are installing library
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
            $<BUILD_INTERFACE:${INCLUDE_DIR}/Interfaces/Adapters>
        PRIVATE
            $<BUILD_INTERFACE:${INCLUDE_DIR}/Adapters>
        )
    #Alias for Image Adapters Library
    add_library(${PROJECT_NAME}::ImageAdaptors ALIAS img-adapters)
endif()