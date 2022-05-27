#include "../main.hpp"

Window myWindow() {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Green);

    onKeyPress(Key::Any, [](Key key) {
        printw("%d ", key);
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .setBorder(border)
        .use(title("Hello, world!", ColorPair(Color::Red, Color::Blue)))
        .use(label("Welcome to the C++", Vector(2, 2)))
        .done();
}
