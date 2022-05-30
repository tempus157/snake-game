#include "../main.hpp"

Window myWindow() {
    auto titleText = useProperty("Hello, World!");

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText = text;
    });

    return Window({
        label(titleText, Vector2(1, 1), ColorPair(Color::Red, Color::Blue)),
        counter("Count: "),
    });
}
