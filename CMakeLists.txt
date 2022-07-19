cmake_minimum_required(VERSION 3.11)
project(snake-game)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(creact)
add_executable(
    game.out
    src/main.cpp
    src/objects/snake.cpp
    src/objects/wall.cpp
    src/scenes/gameScene.cpp
    src/scenes/introScene.cpp
    src/scenes/resultScene.cpp
)

target_link_libraries(game.out creact.out)
