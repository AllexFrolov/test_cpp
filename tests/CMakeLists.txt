cmake_minimum_required(VERSION 3.29)

project(tests)

# Standarts
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_executable  test.cpp)
target_include_directories(test_executable PRIVATE ${CMAKE_SOURCE_DIR}/../build)
target_link_libraries(test_executable  GTest::gtest_main src)

include(GoogleTest)


gtest_discover_tests(test_executable)