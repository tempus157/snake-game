#include "../main.hpp"

Window myWindow() {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Black);

    onKeyPress(Key::Escape, [](const Key &key) {
        quitApp();
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .setBorder(border)
        .useObject(label("Hello, world!", Vector(1, 1), ColorPair(Color::Red, Color::Blue)))
        .useObject(counter("Count: "))
        .done();
}
