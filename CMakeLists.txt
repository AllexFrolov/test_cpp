cmake_minimum_required(VERSION 3.29)

project(CORE)

set(SOURCE_EXE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})

include_directories(src, tests)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} src)

enable_testing()

add_test(NAME my_test COMMAND test_executable)

install(TARGETS CORE DESTINATION bin)


