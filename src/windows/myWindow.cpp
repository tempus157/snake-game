#include "../main.hpp"

Window myWindow(const Vector &position, const Vector &scale) {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Black);

    auto counterText = useProperty("Count: ");
    auto titleText = useProperty("Hello, World!");

    onKeyPress(Key::Enter, [=]() mutable {
        counterText = "You pressed enter: ";
    });

    onKeyPress(Key::Tab, [=]() mutable {
        counterText = "You pressed tab: ";
    });

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText = text;
    });

    return createWindow(position, scale)
        .setColor(Color::Blue, Color::Red)
        .useObject(label(titleText, Vector(1, 1), ColorPair(Color::Red, Color::Blue)))
        .useObject(counter(counterText))
        .done();
}
