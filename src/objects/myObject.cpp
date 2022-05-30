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
        label(titleText, Color::Red),
        $goto(Vector2(2, 1)),
        counter("Count: "),
    });
}
