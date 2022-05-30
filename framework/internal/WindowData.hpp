#ifndef __FRAMEWORK_WINDOW_DATA__
#define __FRAMEWORK_WINDOW_DATA__

#include <ncurses.h>
#include <vector>

class Object;

class WindowData final {
public:
    void useObjects(const std::vector<const Object> &objects);

    void mount();
    void update();
    void destroy();

private:
    WINDOW *window;
    std::vector<const Object> objects;
};

#endif
