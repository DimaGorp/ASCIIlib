#Core Component
add_library(Core)

# Use different directories
# for include cause it differs
# when building and installing
target_include_directories(
        Core
    PUBLIC
        #Use that directory if we are Building library
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        #Use that directory if we are installing library
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        $<BUILD_INTERFACE:${INCLUDE_DIR}/Core>

)

#Alias for Core Library
add_library(${PROJECT_NAME}::Core ALIAS Core)