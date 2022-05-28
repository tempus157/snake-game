#include "main.hpp"
#include <memory>

ObjectData &createObject() {
    return *new ObjectData();
}

WindowData &createWindow() {
    return *new WindowData();
}

App &createApp() {
    return *new App();
}

void quitApp() {
    App::quit();
}

void onKeyPress(const Key &key, const std::function<void()> &callback) {
    Input::onKeyPress(key, callback);
}

Property<std::string> useProperty(const char *value) {
    return Property<std::string>(value);
}

Object label(const Property<std::string> &text) {
    auto update = [=] {
        printw(text->c_str());
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<Vector> &position) {
    auto update = [=] {
        mvprintw(position->y, position->x, text->c_str());
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<ColorPair> &color) {
    auto update = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        printw(text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<Vector> &position,
    const Property<ColorPair> &color) {
    auto update = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        mvprintw(position->y, position->x, text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}
