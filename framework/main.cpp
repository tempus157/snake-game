#include "main.hpp"

ObjectData &createObject() {
    return *new ObjectData();
}

WindowData &createWindow() {
    return *new WindowData();
}

App &createApp() {
    App::instance = new App();
    return *App::instance;
}

Property<std::string> useProperty(const char *value) {
    return Property<std::string>(value);
}

void onKeyPress(Key key, const std::function<void(Key)> &fn) {
    Input::addListener(key, fn);
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
