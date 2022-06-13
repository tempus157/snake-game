#include "../main.hpp"

Scene resultScene() {
    onKeyPress(Key::Q, [] {
        quitApp();
    });

    onKeyPress(Key::Enter, [] {
        changeScene("game");
    });

    return {{
        label("Game Over\n"),
        label("Press Enter to restart\n"),
        label("Press Q to quit"),
    }};
}