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

App &App::setScale(const Vector &scale) {
    this->scale = scale;
    return *this;
}

App &App::setScale(int x, int y) {
    this->scale.x = x;
    this->scale.y = y;
    return *this;
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
    initscr();
    resize_term(scale.y, scale.x);

    Input::mount();
    ColorPair::mount();
    refresh();

    for (const auto &window : windows) {
        window.mount();
    }
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
    endwin();
    delete this;
}
