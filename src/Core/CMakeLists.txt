#Link Source to library
target_sources(
          Core
     PRIVATE
          ${SOURCE_DIR}/Core/ASCIIGenerator.cpp
          ${SOURCE_DIR}/Core/Styles/ASCIIStyle.cpp
     )
#use C++20 Standart
target_compile_features(
          Core
     PUBLIC
          cxx_std_20
     )
find_package(FreeImage QUIET CONFIG)
if(NOT FreeImage_FOUND)
     include(FetchContent)

     FetchContent_Declare(
          FreeImage
          GIT_REPOSITORY https://github.com/danoli3/FreeImage.git
          GIT_TAG        3.19.11
          GIT_SHALLOW    TRUE
     )

     FetchContent_MakeAvailable(FreeImage)

     target_include_directories(
          Core 
     PUBLIC
          $<BUILD_INTERFACE:${FreeImage_SOURCE_DIR}/Source>
     )
endif()

target_link_libraries(Core PRIVATE FreeImage)