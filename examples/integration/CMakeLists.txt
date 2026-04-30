option(FIND_PACKAGE_EX "find_package() Example" OFF)
option(FETCH_CONTENT_EX "FetchContent Example" OFF)

if(FIND_PACKAGE_EX)
    add_subdirectory(FindPackage)
endif()

if(FETCH_CONTENT_EX)
    add_subdirectory(FetchContent)
endif()