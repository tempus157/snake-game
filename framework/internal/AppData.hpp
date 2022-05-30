#ifndef __FRAMEWORK_APP_DATA__
#define __FRAMEWORK_APP_DATA__

#include "../lib/Vector.hpp"

#include <memory>
#include <vector>

class Window;

class AppData final {
public:
    static AppData &getInstance();

    void setScale(const Vector &scale);
    void useWindow(const Window &window);
    void quit();

    void mount() const;
    void update() const;
    void receiveInput() const;
    void destroy() const;

private:
    bool progress = true;
    Vector scale;
    std::vector<const Window> windows;
};

#endif
