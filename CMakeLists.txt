cmake_minimum_required(VERSION 3.15)

project(list)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(list test.cpp)

target_include_directories(list PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/list)
target_link_libraries(list PRIVATE GTest::gtest_main)
target_compile_options(list PRIVATE -Wall -Wextra -Werror)

include(GoogleTest)
gtest_discover_tests(list)