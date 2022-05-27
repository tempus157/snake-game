#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>

bool App::progress = true;
App *App::instance = nullptr;

void App::quit() {
    progress = false;
}

App &App::useWindow(const Window &window) {
    windows.push_back(window);
    return *this;
}

int App::run() const {
    mountWindows();
    input.mount();
    ColorPair::mount();

    updateWindows();

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

void App::updateWindows() const {
    for (const auto &window : windows) {
        window.update();
    }
}
