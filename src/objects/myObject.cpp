#include "../main.hpp"

Object myObject() {
    auto titleText = Property<string>("Hello, world!");

    setInterval([=]() mutable {
        soundBeep();
    },
        1000);

    onKeyPress(Key::Q, [] {
        soundBeep();
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText.set(text);
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
