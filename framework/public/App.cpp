#include "App.hpp"

#include "../private/AppData.hpp"
#include "../private/ExitException.hpp"
#include "../private/Input.hpp"

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
