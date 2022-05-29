#include "main.hpp"
#include <memory>

ObjectData &createObject() {
    return *new ObjectData();
}

WindowData &createWindow(const Vector &position, const Vector &scale) {
    return *new WindowData(position, scale);
}

App &createApp() {
    return *new App();
}

void quitApp() {
    App::quit();
}

std::string readLine() {
    nocbreak();
    int ch;
    std::string input;

    do {
        ch = getch();
        input.push_back(ch);
    } while (ch != '\n');

    cbreak();
    return input;
}

void onKeyPress(const Key &key, const std::function<void()> &callback) {
    Input::onKeyPress(key, callback);
}

Property<std::string> useProperty(const char *value) {
    return Property<std::string>(value);
}

Object label(const Property<std::string> &text) {
    auto update = [=](WINDOW *window) {
        wprintw(window, text->c_str());
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<Vector> &position) {
    auto update = [=](WINDOW *window) {
        mvwprintw(window, position->y, position->x, text->c_str());
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<ColorPair> &color) {
    auto update = [=](WINDOW *window) {
        wattron(window, COLOR_PAIR(color->getAttribute()));
        wprintw(window, text->c_str());
        wattroff(window, COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}

Object label(const Property<std::string> &text, const Property<Vector> &position,
    const Property<ColorPair> &color) {
    auto update = [=](WINDOW *window) {
        wattron(window, COLOR_PAIR(color->getAttribute()));
        mvwprintw(window, position->y, position->x, text->c_str());
        wattroff(window, COLOR_PAIR(color->getAttribute()));
    };

    return Object(update, [] {});
}

Object $if(const Property<bool> &condition, const Object &ifTrue) {
    auto update = [=](WINDOW *window) {
        if (*condition) {
            ifTrue.update(window);
        }
    };

    return Object(update, [] {});
}

Object $if(const Property<bool> &condition, const Object &ifTrue, const Object &ifFalse) {
    auto update = [=](WINDOW *window) {
        if (*condition) {
            ifTrue.update(window);
        } else {
            ifFalse.update(window);
        }
    };

    return Object(update, [] {});
}
