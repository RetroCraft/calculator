cmake_minimum_required (VERSION 2.8)
project (Calculator)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)
set (VERSION_BUILD 1)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

file (GLOB calculator_SRC "src/*.h" , "src/*.cpp")

include_directories ("${PROJECT_BINARY_DIR}")

add_executable (calculate ${calculator_SRC})
