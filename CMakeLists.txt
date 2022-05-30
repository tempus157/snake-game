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
    framework/internal/AppData.cpp
    framework/internal/Input.cpp
    framework/library/ColorPair.cpp
    framework/library/Vector.cpp
    framework/scripts/App.cpp
    framework/scripts/Object.cpp
    framework/scripts/Window.cpp
)
target_link_libraries (main.out ${CURSES_LIBRARIES})
