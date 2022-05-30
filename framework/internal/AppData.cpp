#include "AppData.hpp"

#include "../core/PropertyEvent.hpp"
#include "ColorUtility.hpp"
#include "ExitException.hpp"
#include "Input.hpp"

#include <clocale>
#include <ncurses.h>

AppData::AppData() {
    PropertyEvent::onEveryUpdate(std::bind(&AppData::update, this));
}

AppData &AppData::getInstance() {
    static auto instance = std::unique_ptr<AppData>(new AppData());
    return *instance;
}

void AppData::setScale(const Vector2 &scale) {
    this->scale.x = scale.x;
    this->scale.y = scale.y;
}

void AppData::useObject(const Object &object) {
    objects.push_back(object);
}

void AppData::quit() {
    endwin();
    throw ExitException(1);
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
    while (true) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }
}
