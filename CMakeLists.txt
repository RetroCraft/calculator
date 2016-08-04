cmake_minimum_required (VERSION 2.8)
project (Calculator)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)

file(GLOB calculator_SRC
  "src/*.h",
  "src/*.cpp"
)

add_executable(calculate ${calculator_SRC})
