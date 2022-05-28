cmake_minimum_required (VERSION 3.2)
project (snake-game)

set (CMAKE_CXX_STANDARD 11)
find_package (Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (
    main.out
    src/main.cpp
    src/objects/counter.cpp
    src/windows/myWindow.cpp
    framework/main.cpp
    framework/core/app.cpp
    framework/core/color.cpp
    framework/core/input.cpp
    framework/core/object.cpp
    framework/core/vector.cpp
    framework/core/window.cpp
)
target_link_libraries (main.out ${CURSES_LIBRARIES})
