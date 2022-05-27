#include "../main.hpp"

Window myWindow()
{
    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .use(title("Hello, world!", ColorPair(Color::Red, Color::Blue)))
        .use(label("Welcome to the C++", Vector(2, 2)))
        .done();
}
