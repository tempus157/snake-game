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

void onKeyPress(const Key &key, const std::function<void(const Key &)> &callback) {
    Input::onKeyPress(key, callback);
}

void quitApp() {
    App::quit();
}

Object label(const State<std::string> &text) {
    auto render = [=] {
        printw(text->c_str());
    };

    return Object(render, [] {});
}

Object label(const State<std::string> &text, const State<Vector> &position) {
    auto render = [=] {
        mvprintw(position->y, position->x, text->c_str());
    };

    return Object(render, [] {});
}

Object label(const State<std::string> &text, const State<ColorPair> &color) {
    auto render = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        printw(text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(render, [] {});
}

Object label(const State<std::string> &text,
             const State<Vector> &position,
             const State<ColorPair> &color) {
    auto render = [=] {
        attron(COLOR_PAIR(color->getAttribute()));
        mvprintw(position->y, position->x, text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(render, [] {});
}
