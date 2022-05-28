#include "main.hpp"

ObjectData &createObject() {
    return *new ObjectData();
}

WindowData &createWindow() {
    return *new WindowData();
}

App &createApp() {
    return *new App();
}

State<std::string> useState(const char *value) {
    return State<std::string>(value);
}

void onKeyPress(const Key &key, const std::function<void(const Key &)> &fn) {
    Input::onKeyPress(key, fn);
}

void quitApp() {
    App::quit();
}

Object label(const Property<std::string> &text) {
    auto render = [=] {
        printw(text->c_str());
    };

    return Object(render, [] {});
}

Object label(const Property<std::string> &text, const Property<Vector> &position) {
    auto render = [=] {
        mvprintw(position->y, position->x, text->c_str());
    };

    return Object(render, [] {});
}

Object label(const Property<std::string> &text, const Property<ColorPair> &color) {
    auto render = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        printw(text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(render, [] {});
}

Object label(const Property<std::string> &text,
             const Property<Vector> &position,
             const Property<ColorPair> &color) {
    auto render = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        mvprintw(position->y, position->x, text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(render, [] {});
}
