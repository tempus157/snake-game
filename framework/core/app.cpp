#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>
#include <stdexcept>

App *App::instance = nullptr;

App::App() {
    if (instance) {
        throw std::runtime_error("App already instantiated");
    }
    instance = this;
}

void App::quit() {
    instance->progress = false;
}

App &App::useWindow(const Window &window) {
    windows.push_back(window);
    return *this;
}

int App::run() const {
    mountWindows();
    Input::mount();
    ColorPair::mount();

    updateWindows();

    while (progress) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
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
