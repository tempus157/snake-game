#include "WindowData.hpp"

#include "../core/Object.hpp"
#include "AppData.hpp"

void WindowData::useObjects(const std::vector<const Object> &objects) {
    for (auto &object : objects) {
        this->objects.push_back(object);
    }
}

void WindowData::mount() {
    const auto scale = AppData::getInstance().getScale();
    window = newwin(scale.y, scale.x, 0, 0);
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
