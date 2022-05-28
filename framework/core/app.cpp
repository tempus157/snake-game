#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>
#include <stdexcept>

App *App::instance = nullptr;

App::App() {
    if (instance) {
        throw std::runtime_error("App already exists");
    }
    instance = this;
}

void App::update() {
    if (!instance) {
        throw std::runtime_error("App does not exist");
    }

    for (const auto &window : instance->windows) {
        window.update();
    }
}

void App::quit() {
    if (!instance) {
        throw std::runtime_error("App does not exist");
    }
    instance->progress = false;
}

App &App::loadWindow(const Window &window) {
    windows.push_back(window);
    return *this;
}

int App::run() const {
    mount();
    receiveInput();
    destroy();
    return 0;
}

void App::mount() const {
    setlocale(LC_ALL, "");
    for (const auto &window : windows) {
        window.mount();
    }

    Input::mount();
    ColorPair::mount();
    update();
}

void App::receiveInput() const {
    while (progress) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }
}

void App::destroy() const {
    for (const auto &window : windows) {
        window.destroy();
    }
    delete this;
}
