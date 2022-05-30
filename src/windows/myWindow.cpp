#include "../main.hpp"

Window myWindow(const Vector &position, const Vector &scale) {
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
            label(titleText, Vector(1, 1), ColorPair(Color::Red, Color::Blue)),
            counter("Count: "),
        });
}
