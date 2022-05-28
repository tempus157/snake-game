#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "window.hpp"

#include <functional>
#include <vector>

class App final {
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    App(const std::function<void()> &mount,
        const std::function<void()> &update,
        const std::function<void()> &destroy)
        : mount(mount), update(update), destroy(destroy) {}
};

class AppData final {
public:
    AppData();
    static void quit();
    AppData &useWindow(const Window &window);
    int run() const;

private:
    static AppData *instance;
    bool progress = true;
    std::vector<const Window> windows;
    App build() const;
};

#endif
