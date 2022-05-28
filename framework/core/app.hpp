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
    const std::function<void()> receiveInput;

    App(const std::function<void()> &mount,
        const std::function<void()> &update,
        const std::function<void()> &destroy,
        const std::function<void()> &receiveInput)
        : mount(mount), update(update), destroy(destroy), receiveInput(receiveInput) {}
};

class AppData final {
public:
    AppData();
    static void quit();
    AppData &useWindow(const Window &window);
    App done() const;

private:
    static AppData *instance;
    bool progress = true;
    std::vector<const Window> windows;
};

#endif
