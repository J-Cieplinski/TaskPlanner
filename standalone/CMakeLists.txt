cmake_minimum_required(VERSION 3.14...3.22)

project(TaskPlannerStandalone LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(NAME TaskPlanner SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create standalone executable ----

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 OUTPUT_NAME "TaskPlannerApp")

target_link_libraries(${PROJECT_NAME} TaskPlanner::TaskPlanner)
