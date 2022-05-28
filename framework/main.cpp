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

Object label(const State<std::string> &text) {
    auto update = [=] {
        printw(text->c_str());
    };

    return Object(update, [] {});
}

Object label(const State<std::string> &text, const State<Vector> &position) {
    auto update = [=] {
        mvprintw(position->y, position->x, text->c_str());
    };

    return Object(update, [] {});
}

Object label(const State<std::string> &text, const State<ColorPair> &color) {
    auto update = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        printw(text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}

Object label(const State<std::string> &text, const State<Vector> &position,
    const State<ColorPair> &color) {
    auto update = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        mvprintw(position->y, position->x, text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}

void onKeyPress(const Key &key, const std::function<void(const Key &)> &callback) {
    Input::onKeyPress(key, callback);
}

void quitApp() {
    App::quit();
}

State<std::string> useState(const char *value) {
    return State<std::string>(value);
}
