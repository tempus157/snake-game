#include "app.h"
#include "color.h"

#include <chrono>
#include <clocale>
#include <ncurses.h>
#include <thread>

namespace InternalCreact {
    void mountApp() {
        setlocale(LC_ALL, "");
        initscr();
        mountColor();
        // Mount input

        size.x = size.x < 1 ? getmaxx(stdscr) : size.x;
        size.y = size.y < 1 ? getmaxy(stdscr) : size.y;
        resize_term(size.y, size.x);
    }

    void updateApp() {
        clear();
        scenes[activeSceneName]()(Creact::Vector::Zero);
        refresh();
    }

    void receiveInput() {
        while (shouldProgress) {
            // Implement
        }
    }
}

namespace Creact {
    void resizeTerminal(const int x, const int y) {
        InternalCreact::size = {x, y};
    }

    void registerScene(const std::string &name,
        const std::function<Element()> scene) {
        InternalCreact::scenes[name] = scene;
    }

    int runApp(const std::string &sceneName) {
        InternalCreact::mountApp();
        changeScene(sceneName);

        while (InternalCreact::shouldProgress) {
            if (InternalCreact::shouldUpdate) {
                InternalCreact::shouldUpdate = false;
                InternalCreact::updateApp();
            }

            while (InternalCreact::shouldProgress &&
                   !InternalCreact::shouldUpdate) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }

        endwin();
        return 0;
    }

    void changeScene(const std::string &name) {
        InternalCreact::activeSceneName = name;
        InternalCreact::shouldUpdate = true;
    }

    void quitApp() {
        InternalCreact::shouldProgress = false;
    }
}
