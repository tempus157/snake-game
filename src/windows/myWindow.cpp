#include "../main.hpp"

Window myWindow() {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Green);

    onKeyPress(Key::Escape, [](Key key) {
        quitApp();
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .setBorder(border)
        .useObject(title("Hello, world!", ColorPair(Color::Red, Color::Blue)))
        .useObject(label("Welcome to the C++", Vector(2, 2)))
        .done();
}
