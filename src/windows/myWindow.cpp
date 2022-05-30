#include "../main.hpp"

Window myWindow(const Vector2 &position, const Vector2 &scale) {
    auto titleText = useProperty("Hello, World!");

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText = text;
    });

    return Window()
        .setPosition(position)
        .setScale(scale)
        .useObjects({
            label(titleText, Vector2(1, 1), ColorPair(Color::Red, Color::Blue)),
            counter("Count: "),
        });
}
