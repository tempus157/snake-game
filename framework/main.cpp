#include "main.hpp"

#include "./internal/AppData.hpp"
#include "./internal/Input.hpp"

#include <memory>
#include <ncurses.h>

Object label(const Property<std::string> &text) {
    auto update = [=](const Vector2 &origin) {
        printw(text->c_str());
    };

    return Object(update);
}

Object label(const Property<std::string> &text, const Property<Vector2> &position) {
    auto update = [=](const Vector2 &origin) {
        mvprintw(position->y, position->x, text->c_str());
    };

    return Object(update);
}

Object label(const Property<std::string> &text, const Property<ColorPair> &color) {
    auto update = [=](const Vector2 &origin) {
        attron(COLOR_PAIR(color->getAttribute()));
        printw(text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update);
}

Object label(const Property<std::string> &text, const Property<Vector2> &position,
    const Property<ColorPair> &color) {
    auto update = [=](const Vector2 &origin) {
        attron(COLOR_PAIR(color->getAttribute()));
        mvprintw(position->y, position->x, text->c_str());
        attroff(COLOR_PAIR(color->getAttribute()));
    };

    return Object(update);
}

Object $goto(const Property<Vector2> &position) {
    auto update = [=](const Vector2 &origin) {
        move(origin.y + position->y, origin.x + position->x);
    };

    return Object(update);
}

Object $if(const Property<bool> &condition, const Object &ifTrue) {
    auto update = [=](const Vector2 &origin) {
        if (*condition) {
            ifTrue.update(origin);
        }
    };

    return Object(update);
}

Object $if(const Property<bool> &condition, const Object &ifTrue, const Object &ifFalse) {
    auto update = [=](const Vector2 &origin) {
        if (*condition) {
            ifTrue.update(origin);
        } else {
            ifFalse.update(origin);
        }
    };

    return Object(update);
}

Property<std::string> useProperty(const char *value) {
    return Property<std::string>(value);
}

void quitApp() {
    AppData::getInstance().quit();
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
