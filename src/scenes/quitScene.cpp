#include "../main.hpp"

Scene quitScene() {
    onKeyPress(Key::Q, [] {
        changeScene("sub");
        quitApp();
    });

    return Object({
        label("Press Q to quit.", Color::Red, Color::Blue),
    });
}