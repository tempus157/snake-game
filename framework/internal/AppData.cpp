#include "AppData.hpp"

#include "ColorUtility.hpp"
#include "Input.hpp"

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

void AppData::useObject(const Object &object) {
    objects.push_back(object);
}

void AppData::quit() {
    progress = false;
}

void AppData::mount() {
    setlocale(LC_ALL, "");
    initscr();

    if (scale.x < 1) {
        scale.x = getmaxx(stdscr);
    }
    if (scale.y < 1) {
        scale.y = getmaxy(stdscr);
    }

    resize_term(scale.y, scale.x);
    Input::mount();
    ColorUtility::mount();
}

void AppData::update() const {
    clear();
    for (const auto &object : objects) {
        object.update(Vector2::Zero);
    }
    refresh();
}

void AppData::receiveInput() const {
    while (progress) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }
}

void AppData::destroy() const {
    endwin();
}
