#include "../main.hpp"

Object myObject() {
    auto titleText = Property<string>("Hello, world!");
    auto intervalID = Property<int>();

    onKeyPress(Key::Q, [] {
        soundBeep();
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto id = setInterval([=]() mutable {
            soundBeep();
        },
            1000);
        intervalID.set(id);
    });

    onKeyPress(Key::Backspace, [=]() {
        clearInterval(*intervalID);
    });

    return Object({
        $goto(Vector2(1, 1)),
        border('*', Vector2(40, 20)),
        $goto(Vector2(10, 5)),
        box('s', Vector2(10, 5), Color::Cyan, Color::Cyan),
        $goto(Vector2(0, 0)),
        label(titleText, Color::Red, Color::Blue),
        $goto(Vector2(3, 2)),
        counter("Count: "),
    });
}
