#include "AppData.hpp"

#include "../library/ColorPair.hpp"
#include "../scripts/Window.hpp"
#include "Input.hpp"

#include <clocale>
#include <ncurses.h>

AppData *AppData::instance = nullptr;

AppData &AppData::getInstance() {
    if (!instance) {
        instance = new AppData();
    }
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
        window.mount();
    }
    update();
}

void AppData::update() const {
    for (const auto &window : windows) {
        window.update();
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
        window.destroy();
    }
    endwin();
    delete this;
}
