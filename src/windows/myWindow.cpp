#include "../main.hpp"

Window myWindow() {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Black);

    static auto counterText = useState("Count: ");

    onKeyPress(Key::Enter, [] {
        counterText = "You pressed enter: ";
    });

    onKeyPress(Key::Tab, [] {
        counterText = "You pressed tab: ";
    });

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .setBorder(border)
        .useObject(label("Hello, world!", Vector(1, 1), ColorPair(Color::Red, Color::Blue)))
        .useObject(counter(counterText))
        .done();
}
