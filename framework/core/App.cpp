#include "App.hpp"

#include "../internal/AppData.hpp"
#include "../internal/Input.hpp"

App &App::setScale(const Vector2 &scale) {
    AppData::getInstance().setScale(scale);
    return *this;
}

App &App::useWindow(const Window &window) {
    AppData::getInstance().useWindow(window);
    return *this;
}

int App::run() const {
    AppData::getInstance().mount();
    AppData::getInstance().receiveInput();
    AppData::getInstance().destroy();
    return 0;
}

// TEMP
void App::update() {
    AppData::getInstance().update();
}
