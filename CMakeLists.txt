cmake_minimum_required(VERSION 3.29)

project(test_cpp)

set(SOURCE_EXE main.cpp)

add_executable(main ${SOURCE_EXE})

include_directories(src, tests)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(main src)
