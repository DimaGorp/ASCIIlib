set(SOURCES main.cpp)

add_executable(example1 ${SOURCES})

message(${INCLUDE_DIR})
target_include_directories(example1 PUBLIC ${INCLUDE_DIR})