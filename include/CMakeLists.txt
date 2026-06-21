#Core Component
add_library(Image)

# Use different directories
# for include cause it differs
# when building and installing
target_include_directories(
        Image
    PUBLIC
        #Use that directory if we are Building library
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        #Use that directory if we are installing library
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>

        $<BUILD_INTERFACE:${INCLUDE_DIR}/Interfaces>
    PRIVATE
        $<BUILD_INTERFACE:${INCLUDE_DIR}/Core>
        $<BUILD_INTERFACE:${INCLUDE_DIR}/Core/Adapters>
)

#Alias for Core Library
add_library(${PROJECT_NAME}::Image ALIAS Image)