#include "WindowData.hpp"

#include "../core/Object.hpp"

void WindowData::setPosition(const Vector &position) {
    this->position = position;
}

void WindowData::setScale(const Vector &scale) {
    this->scale = scale;
}

void WindowData::setColor(const ColorPair &color) {
    this->color = color;
}

void WindowData::setBorderCh(char ch) {
    this->borderCh = ch;
}

void WindowData::setBorderColor(const ColorPair &color) {
    this->borderColor = color;
}

void WindowData::useObjects(const std::vector<const Object> &objects) {
    for (auto &object : objects) {
        this->objects.push_back(object);
    }
}

void WindowData::mount() {
    window = newwin(scale.y, scale.x, position.y, position.x);
}

void WindowData::update() {
    wclear(window);
    for (const auto &object : objects) {
        object.update(window);
    }
    wrefresh(window);
}

void WindowData::destroy() {
    endwin();
}
