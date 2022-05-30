#include "../main.hpp"

Object myObject() {
    auto titleText = useProperty("Hello, World!");

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText = text;
    });

    return Object({
        label(titleText, ColorPair(Color::Red, Color::Blue)),
        $goto(Vector2(2, 1)),
        counter("Count: "),
    });
}
