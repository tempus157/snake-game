#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "window.hpp"

#include <functional>
#include <vector>

class AppObj final {
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    AppObj(const std::function<void()> &mount,
           const std::function<void()> &update,
           const std::function<void()> &destroy)
        : mount(mount), update(update), destroy(destroy) {}
};

class App final {
public:
    App();
    static void quit();
    App &useWindow(const Window &window);
    int run() const;

private:
    static App *instance;
    bool progress = true;
    std::vector<const Window> windows;
    AppObj build() const;
};

#endif
