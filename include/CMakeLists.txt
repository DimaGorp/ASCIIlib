option(ADAPTERS_LIBRARY "Library of Adapters" OFF)
option(SFML_ADAPTER "SFML Library Image Adapter" OFF)




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
    if(SFML_ADAPTER)
        #SFML Adapter
        add_library(sfml-adapter)
        
        target_include_directories(
                sfml-adapter
            PUBLIC
                #Use that directory if we are Building library
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                #Use that directory if we are installing library
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        
                $<BUILD_INTERFACE:${INCLUDE_DIR}/Interfaces/Adapters>
            PRIVATE
                $<BUILD_INTERFACE:${INCLUDE_DIR}/Adapters>
        )
        
        #link SFML
        find_package(SFML 3.0 COMPONENTS Graphics CONFIG REQUIRED)
        target_link_libraries(sfml-adapter PRIVATE SFML::Graphics)
        #Alias for Core Library
        add_library(${PROJECT_NAME}::SFMLImage ALIAS sfml-adapter)
    endif()
endif()