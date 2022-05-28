#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <ncurses.h>
#include <stdexcept>

AppData *AppData::instance = nullptr;

App *App::instance = nullptr;

App::App(const std::function<void()> &mount,
         const std::function<void()> &update,
         const std::function<void()> &destroy,
         const std::function<void()> &receiveInput)
    : mount(mount), update(update), destroy(destroy), receiveInput(receiveInput) {
    if (instance) {
        throw std::runtime_error("App already exists");
    }
    instance = this;
}

AppData::AppData() {
    if (instance) {
        throw std::runtime_error("AppData already exists");
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

App AppData::done() const {
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

        delete this;
    };

    const auto receiveInput = [&]() {
        while (progress) {
            const auto key = Input::readKey();
            Input::notifyKeyPress(key);
        }
    };

    return App(mount, update, destroy, receiveInput);
}
