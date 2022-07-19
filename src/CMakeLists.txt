add_executable(
    game.out
    main.cpp
    objects/snake.cpp
    objects/wall.cpp
    scenes/gameScene.cpp
    scenes/introScene.cpp
    scenes/resultScene.cpp
)

target_link_libraries(game.out creact)
