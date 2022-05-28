#include "../main.hpp"

Window myWindow() {
    auto border = Border('*');
    border.color = ColorPair(Color::Yellow, Color::Black);

    static auto counterText = useProperty("Count: ");
    static auto titleText = useProperty("Hello, World!");

    onKeyPress(Key::Enter, [] {
        counterText = "You pressed enter: ";
    });

    onKeyPress(Key::Tab, [] {
        counterText = "You pressed tab: ";
    });

    onKeyPress(Key::Escape, [] {
        quitApp();
    });

    onKeyPress(Key::Space, [] {
        const auto text = readLine();
        titleText = text;
    });

    return createWindow()
        .setScale(40, 20)
        .setColor(Color::Blue, Color::Red)
        .setBorder(border)
        .useObject(label(titleText, Vector(1, 1), ColorPair(Color::Red, Color::Blue)))
        .useObject(counter(counterText))
        .done();
}
