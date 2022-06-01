#include "App.hpp"

#include "../private/AppData.hpp"
#include "../private/ExitException.hpp"
#include "../private/Input.hpp"

#include <ncurses.h>

App &App::setScale(const Vector2 &scale) {
    AppData::getInstance().setScale(scale);
    return *this;
}

App &App::useScene(const std::string &name, const SceneFunction &scene) {
    AppData::getInstance().useScene(name, scene);
    return *this;
}

int App::run(const std::string &sceneName) const {
    try {
        AppData::getInstance().mount();
        AppData::getInstance().changeScene(sceneName);
        AppData::getInstance().receiveInput();
    } catch (const ExitException &exit) {
        return exit.code;
    }
    return 0;
}
