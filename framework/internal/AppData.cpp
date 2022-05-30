#include "AppData.hpp"

#include "../core/Window.hpp"
#include "../lib/ColorPair.hpp"
#include "Input.hpp"
#include "WindowData.hpp"

#include <clocale>
#include <ncurses.h>

AppData &AppData::getInstance() {
    static auto instance = std::unique_ptr<AppData>(new AppData());
    return *instance;
}

void AppData::setScale(const Vector &scale) {
    this->scale = scale;
}

void AppData::useWindow(const Window &window) {
    windows.push_back(window);
}

void AppData::quit() {
    progress = false;
}

void AppData::mount() const {
    setlocale(LC_ALL, "");
    initscr();
    resize_term(scale.y, scale.x);

    Input::mount();
    ColorPair::mount();
    refresh();

    for (const auto &window : windows) {
        window.data->mount();
    }
    update();
}

void AppData::update() const {
    for (const auto &window : windows) {
        window.data->update();
    }
}

void AppData::receiveInput() const {
    while (progress) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }
}

void AppData::destroy() const {
    for (const auto &window : windows) {
        window.data->destroy();
    }
    endwin();
}
