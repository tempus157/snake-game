#include "App.hpp"

#include "../internal/AppData.hpp"
#include "../internal/Input.hpp"

App &App::setScale(const Vector2 &scale) {
    AppData::getInstance().setScale(scale);
    return *this;
}

App &App::useObject(const Object &object) {
    AppData::getInstance().useObject(object);
    return *this;
}

int App::run() const {
    AppData::getInstance().mount();
    AppData::getInstance().update();
    AppData::getInstance().receiveInput();
    AppData::getInstance().destroy();
    return 0;
}

// TEMP
void App::update() {
    AppData::getInstance().update();
}
