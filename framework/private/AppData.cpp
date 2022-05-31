#include "AppData.hpp"

#include "../public/LifeCycle.hpp"
#include "AsyncHandler.hpp"
#include "ColorUtility.hpp"
#include "ExitException.hpp"
#include "Input.hpp"

#include <clocale>
#include <ncurses.h>

AppData::AppData() {
    LifeCycle::onEveryUpdate(std::bind(&AppData::update, this));
}

AppData &AppData::getInstance() {
    static auto instance = std::unique_ptr<AppData>(new AppData());
    return *instance;
}

void AppData::setScale(const Vector2 &scale) {
    this->scale.x = scale.x;
    this->scale.y = scale.y;
}

void AppData::useScene(const std::string &name, const SceneFunction &scene) {
    scenes[name] = scene;
}

void AppData::changeScene(const std::string &name) {
    activeScene.destroy();
    activeScene = scenes[name]();
    update();
}

void AppData::quit() {
    endwin();
    AsyncHandler::clearAll();
    throw ExitException(1);
}

void AppData::mount() {
    setlocale(LC_ALL, "");
    initscr();

    scale.x = scale.x < 1 ? getmaxx(stdscr) : scale.x;
    scale.y = scale.y < 1 ? getmaxy(stdscr) : scale.y;
    resize_term(scale.y, scale.x);

    Input::mount();
    ColorUtility::mount();
}

void AppData::update() const {
    clear();
    activeScene.update();
    refresh();
}

void AppData::receiveInput() const {
    while (true) {
        const auto key = Input::readKey();
        Input::notifyKeyPress(key);
    }
}
