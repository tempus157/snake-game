cmake_minimum_required (VERSION 3.2)
project (snake-game)

set (CMAKE_CXX_STANDARD 11)
find_package (Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (
    game.out
    src/main.cpp
    src/objects/snake.cpp
    src/objects/wall.cpp
    src/scenes/gameScene.cpp
    src/scenes/introScene.cpp
    src/scenes/resultScene.cpp
    creact/main.cpp
    creact/public/App.cpp
    creact/public/LifeCycle.cpp
    creact/public/Object.cpp
    creact/public/Scene.cpp
    creact/public/Vector.cpp
    creact/private/AppData.cpp
    creact/private/AsyncHandler.cpp
    creact/private/ColorUtility.cpp
    creact/private/Input.cpp
)
target_link_libraries (game.out ${CURSES_LIBRARIES})
