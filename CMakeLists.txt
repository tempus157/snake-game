cmake_minimum_required (VERSION 3.2)
project (snake-game)

set (CMAKE_CXX_STANDARD 11)
find_package (Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (
    main.out
    src/main.cpp
    src/objects/logger.cpp
    src/objects/snake.cpp
    src/objects/wall.cpp
    src/scenes/gameScene.cpp
    src/scenes/resultScene.cpp
    framework/main.cpp
    framework/public/App.cpp
    framework/public/LifeCycle.cpp
    framework/public/Object.cpp
    framework/public/Scene.cpp
    framework/public/Vector.cpp
    framework/private/AppData.cpp
    framework/private/AsyncHandler.cpp
    framework/private/ColorUtility.cpp
    framework/private/Input.cpp
)
target_link_libraries (main.out ${CURSES_LIBRARIES})
