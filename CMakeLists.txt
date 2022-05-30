cmake_minimum_required (VERSION 3.2)
project (snake-game)

set (CMAKE_CXX_STANDARD 11)
find_package (Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (
    main.out
    src/main.cpp
    src/objects/myObject.cpp
    src/objects/counter.cpp
    framework/main.cpp
    framework/internal/AppData.cpp
    framework/internal/Input.cpp
    framework/lib/ColorPair.cpp
    framework/lib/Vector.cpp
    framework/core/App.cpp
    framework/core/Object.cpp
)
target_link_libraries (main.out ${CURSES_LIBRARIES})
