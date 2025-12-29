set(SOURCES 
    main.cpp
    "${SOURCE_DIR}/ASKII.cpp"
    )

add_executable(example1 ${SOURCES})

target_include_directories(example1 PUBLIC ${INCLUDE_DIR})