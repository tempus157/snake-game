#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "../lib/Color.hpp"
#include "../lib/ColorPair.hpp"
#include "../lib/Vector.hpp"
#include "Object.hpp"

#include <functional>
#include <ncurses.h>
#include <vector>

template <typename T>
class Optional {
public:
    Optional() : hasValue(false) {}
    Optional(const std::nullptr_t &value) : Optional() {}
    Optional(const T &value) : value(value), hasValue(true) {}

    operator bool() const {
        return hasValue;
    }

    T operator*() const {
        if (!hasValue) {
            throw std::runtime_error("Optional does not have a value");
        }

        return value;
    }

    const T *operator->() const {
        if (!hasValue) {
            throw std::runtime_error("Optional does not have a value");
        }

        return &value;
    }

    Optional<T> &operator=(const std::nullptr_t &value) {
        hasValue = false;
        return *this;
    }

    Optional<T> &operator=(const T &value) {
        this->value = value;
        this->hasValue = true;
        return *this;
    }

private:
    T value;
    bool hasValue;
};

class Border final {
public:
    unsigned int left;
    unsigned int right;
    unsigned int top;
    unsigned int bottom;
    unsigned int topLeft;
    unsigned int topRight;
    unsigned int bottomLeft;
    unsigned int bottomRight;
    Optional<ColorPair> color;

    Border();
    Border(unsigned int ch);
    void update() const;
};

class Window final {
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    Window(const std::function<void()> &mount,
        const std::function<void()> &update,
        const std::function<void()> &destroy);
};

class WindowData final {
public:
    WindowData(const Vector &position, const Vector &scale);
    WindowData &setColor(const ColorPair color);
    WindowData &setColor(const Color &foreground, const Color &background);
    WindowData &setBorder(const Optional<Border> &border);
    WindowData &useObject(const Object &object);
    Window done();

private:
    WINDOW *window;
    const Vector position;
    const Vector scale;
    ColorPair color;
    Optional<Border> border;
    std::vector<const Object> objects;
};

#endif
