#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>

bool App::progress = true;

void App::quit() {
    progress = false;
}

App &App::addWindow(const Window &window) {
    windows.push_back(window);
    return *this;
}

int App::run() const {
    mountWindows();
    input.mount();
    ColorPair::mount();

    for (const auto &window : windows) {
        window.update();
    }

    while (progress) {
        const auto key = input.readKey();
        input.notifyListeners(key);
    }

    for (const auto &window : windows) {
        window.destroy();
    }

    delete this;
    return 0;
}

void App::mountWindows() const {
    setlocale(LC_ALL, "");

    for (const auto &window : windows) {
        window.mount();
    }
}
