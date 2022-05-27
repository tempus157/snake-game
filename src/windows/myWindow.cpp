#include "../main.hpp"

Window myWindow() {
    onKeyPress(Key::A, [] {
        printf("Exit");
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .use(title("Hello, world!", ColorPair(Color::Red, Color::Blue)))
        .use(label("Welcome to the C++", Vector(2, 2)))
        .done();
}
