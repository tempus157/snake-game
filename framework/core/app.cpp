#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>
#include <stdexcept>

AppData *AppData::instance = nullptr;

AppData::AppData() {
    if (instance) {
        throw std::runtime_error("App already instantiated");
    }
    instance = this;
}

void AppData::quit() {
    instance->progress = false;
}

AppData &AppData::useWindow(const Window &window) {
    windows.push_back(window);
    return *this;
}

int AppData::run() const {
    const auto app = build();
    app.mount();
    app.update();

    while (progress) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }

    app.destroy();
    delete this;
    return 0;
}

App AppData::build() const {
    const auto mount = [&]() {
        setlocale(LC_ALL, "");
        for (const auto &window : windows) {
            window.mount();
        }

        Input::mount();
        ColorPair::mount();
    };

    const auto update = [&]() {
        for (const auto &window : windows) {
            window.update();
        }
    };

    const auto destroy = [&]() {
        for (const auto &window : windows) {
            window.destroy();
        }
    };

    return App(mount, update, destroy);
}
