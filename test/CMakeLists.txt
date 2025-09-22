# cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain dsa_practice_lib)

target_sources(tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_practice_tests.cpp
)

include(CTest)
include(Catch)
catch_discover_tests(tests)

add_custom_target(tests_run ALL ctest --output-on-failure)
add_dependencies(tests_run tests)
