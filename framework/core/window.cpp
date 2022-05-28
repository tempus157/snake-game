#include "window.hpp"

Border::Border() : Border('+') {}

Border::Border(unsigned int ch)
    : left(ch), right(ch), top(ch), bottom(ch),
      topLeft(ch), topRight(ch), bottomLeft(ch), bottomRight(ch) {}

void Border::update() const {
    if (color) {
        attron(COLOR_PAIR(color->getAttribute()));
    }

    border(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);

    if (color) {
        attroff(COLOR_PAIR(color->getAttribute()));
    }
}

Window::Window(const std::function<void()> &mount,
    const std::function<void()> &update,
    const std::function<void()> &destroy)
    : mount(mount), update(update), destroy(destroy) {}

WindowData::WindowData(const Vector &position, const Vector &scale)
    : position(position), scale(scale) {}

WindowData &WindowData::setColor(const ColorPair color) {
    this->color = color;
    return *this;
}

WindowData &WindowData::setColor(const Color &foreground, const Color &background) {
    this->color.foreground = foreground;
    this->color.background = background;
    return *this;
}

WindowData &WindowData::setBorder(const Optional<Border> &border) {
    this->border = border;
    return *this;
}

WindowData &WindowData::useObject(const Object &object) {
    objects.push_back(object);
    return *this;
}

Window WindowData::done() {
    const auto mount = [&] {
        window = newwin(scale.y, scale.x, position.y, position.x);
        wbkgd(window, COLOR_PAIR(color.getAttribute()));
    };

    const auto update = [&] {
        wclear(window);
        for (const auto &object : objects) {
            object.update(window);
        }

        if (border) {
            border->update();
        }
        wrefresh(window);
    };

    const auto destroy = [&] {
        for (const auto &object : objects) {
            object.destroy();
        }
        endwin();
        delete this;
    };

    return Window(mount, update, destroy);
}