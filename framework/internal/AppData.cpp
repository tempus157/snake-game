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

Vector2 AppData::getScale() const {
    return scale;
}

void AppData::setScale(const Vector2 &scale) {
    this->scale.x = scale.x;
    this->scale.y = scale.y;
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

    const auto x = scale.x > 0 ? scale.x : getmaxx(stdscr);
    const auto y = scale.y > 0 ? scale.y : getmaxy(stdscr);
    resize_term(y, x);

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
