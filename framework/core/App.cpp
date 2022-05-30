#include "App.hpp"

#include "../internal/AppData.hpp"
#include "../internal/ExitException.hpp"
#include "../internal/Input.hpp"

#include <ncurses.h>

App &App::setScale(const Vector2 &scale) {
    AppData::getInstance().setScale(scale);
    return *this;
}

App &App::useObject(const Object &object) {
    AppData::getInstance().useObject(object);
    return *this;
}

int App::run() const {
    try {
        AppData::getInstance().mount();
        AppData::getInstance().update();
        AppData::getInstance().receiveInput();
    } catch (const ExitException &exit) {
        return exit.code;
    }
    return 0;
}
