include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    FIND_PACKAGE_ARGS NAMES GTest 
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
add_executable(
  NNISTest
  NNISTest.cpp
)
target_link_libraries(
  NNISTest
  GTest::gtest_main
  ASCIIlib::ImageGenerator
)

include(GoogleTest)
gtest_discover_tests(NNISTest)