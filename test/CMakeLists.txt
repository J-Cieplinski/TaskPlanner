cmake_minimum_required(VERSION 3.14...3.22)

project(TaskPlannerTests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage("gh:google/googletest@1.15.2")
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")

if(TEST_INSTALLED_VERSION)
  find_package(TaskPlanner REQUIRED)
else()
  CPMAddPackage(NAME TaskPlanner SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)
endif()

# ---- Create binary ----

add_executable(${PROJECT_NAME})

# cmake-format: off
target_sources(${PROJECT_NAME}
  PUBLIC
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Entry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Date.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Priority.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Serialization.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Sorters.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Time.cpp
)
# cmake-format: on

target_link_libraries(${PROJECT_NAME} GTest::gtest_main TaskPlanner::TaskPlanner)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

# enable compiler warnings
if(NOT TEST_INSTALLED_VERSION)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(TaskPlanner PUBLIC -Wall -Wpedantic -Wextra -Werror)
  elseif(MSVC)
    target_compile_options(TaskPlanner PUBLIC /W4 /WX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
endif()

# ---- Add Tests ----

enable_testing()

# Note: doctest and similar testing frameworks can automatically configure CMake tests. For other
# testing frameworks add the tests target instead: add_test(NAME ${PROJECT_NAME} COMMAND
# ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(TaskPlanner PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(TaskPlanner PUBLIC -fprofile-arcs -ftest-coverage)
endif()
