#include "main.hpp"

#include "./private/AppData.hpp"
#include "./private/AsyncHandler.hpp"
#include "./private/ColorUtility.hpp"
#include "./private/Input.hpp"

#include <memory>
#include <ncurses.h>

#undef border

Object label(const Property<string> &text) {
    auto update = [=](const Vector2 &origin) {
        printw(text->c_str());
    };

    return Object(update);
}

Object label(const Property<string> &text,
    const Property<Color> &foreground, const Property<Color> &background) {
    auto update = [=](const Vector2 &origin) {
        ColorUtility::enableColor(*foreground, *background);
        printw(text->c_str());
        ColorUtility::disableColor(*foreground, *background);
    };

    return Object(update);
}

Object box(const Property<char> &ch, const Property<Vector2> &scale) {
    auto update = [=](const Vector2 &origin) {
        const auto current = Vector2(getcurx(stdscr), getcury(stdscr));
        for (auto y = 0; y < scale->y; ++y) {
            for (auto x = 0; x < scale->x; ++x) {
                mvaddch(current.y + y, current.x + x, *ch);
            }
        }
    };

    return Object(update);
}

Object box(const Property<char> &ch, const Property<Vector2> &scale,
    const Property<Color> &foreground, const Property<Color> &background) {
    auto update = [=](const Vector2 &origin) {
        const auto current = Vector2(getcurx(stdscr), getcury(stdscr));
        ColorUtility::enableColor(*foreground, *background);

        for (auto y = 0; y < scale->y; ++y) {
            for (auto x = 0; x < scale->x; ++x) {
                mvaddch(current.y + y, current.x + x, *ch);
            }
        }

        ColorUtility::disableColor(*foreground, *background);
    };

    return Object(update);
}

Object border(const Property<char> &ch, const Property<Vector2> &scale) {
    auto update = [=](const Vector2 &origin) {
        const auto current = Vector2(getcurx(stdscr), getcury(stdscr));
        for (auto y = 0; y < scale->y; ++y) {
            for (auto x = 0; x < scale->x; ++x) {
                if (x == 0 || y == 0 || x == scale->x - 1 || y == scale->y - 1) {
                    mvaddch(current.y + y, current.x + x, *ch);
                }
            }
        }
    };

    return Object(update);
}

Object border(const Property<char> &ch, const Property<Vector2> &scale,
    const Property<Color> &foreground, const Property<Color> &background) {
    auto update = [=](const Vector2 &origin) {
        const auto current = Vector2(getcurx(stdscr), getcury(stdscr));
        ColorUtility::enableColor(*foreground, *background);

        for (auto y = 0; y < scale->y; ++y) {
            for (auto x = 0; x < scale->x; ++x) {
                if (x == 0 || y == 0 || x == scale->x - 1 || y == scale->y - 1) {
                    mvaddch(current.y + y, current.x + x, *ch);
                }
            }
        }

        ColorUtility::disableColor(*foreground, *background);
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

Object $union(const std::vector<const Object> &objects) {
    auto update = [=](const Vector2 &origin) {
        for (auto object : objects) {
            object.update(origin);
        }
    };

    return Object(update);
}

void changeScene(const string &name) {
    AppData::getInstance().changeScene(name);
}

void quitApp() {
    AppData::getInstance().quit();
}

void soundBeep() {
    beep();
}

string readLine() {
    nocbreak();
    int ch;
    string input;

    do {
        ch = getch();
        input.push_back(ch);
    } while (ch != '\n');

    cbreak();
    return input;
}

int asyncCall(int delay, const Callback &callback) {
    return AsyncHandler::setCall(callback, delay);
}

int asyncLoop(int delay, const Callback &callback) {
    return AsyncHandler::setLoop(callback, delay);
}

void clearAsync(int id) {
    AsyncHandler::clear(id);
}

void onKeyPress(const Key &key, const Callback &callback) {
    Input::onKeyPress(key, callback);
}

void onDestroy(const Callback &callback) {
    LifeCycle::onDestroy(callback);
}
