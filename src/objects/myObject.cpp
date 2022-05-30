#include "../main.hpp"

Object myObject() {
    auto titleText = useProperty("Hello, world!");

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText = text;
    });

    return Object({
        $goto(Vector2(1, 1)),
        panel('*', Vector2(40, 20)),
        $goto(Vector2(10, 5)),
        panel('s', Vector2(10, 5), Color::Cyan, Color::Cyan),
        $goto(Vector2(0, 0)),
        label(titleText, Color::Red, Color::Blue),
        $goto(Vector2(2, 1)),
        counter("Count: "),
    });
}
