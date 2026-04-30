project(FetchContentExample LANGUAGES CXX)

add_executable(FetchContentExample main.cpp)

set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/examples/integration/FetchContent)
include(FetchContent)

FetchContent_Declare(
    ASCII
    GIT_REPOSITORY https://github.com/DimaGorp/ASCIIlib.git
    GIT_TAG        origin/feature/CMake
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(ASCII)
target_link_libraries(FetchContentExample PUBLIC ASCIIlib::Core)