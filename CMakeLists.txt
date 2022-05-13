cmake_minimum_required (VERSION 3.2)
project (snake-game)

set (CMAKE_CXX_STANDARD 11)
find_package (Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (game.out src/main.cpp src/windows/mainWindow.cpp core/app.cpp core/window.cpp)
target_link_libraries (game.out ${CURSES_LIBRARIES})
