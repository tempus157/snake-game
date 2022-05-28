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

WindowData &WindowData::setScale(const Vector &scale) {
    this->scale = scale;
    return *this;
}

WindowData &WindowData::setScale(int x, int y) {
    this->scale.x = x;
    this->scale.y = y;
    return *this;
}

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

Window WindowData::done() const {
    const auto mount = [&] {
        initscr();
        resize_term(scale.y, scale.x);
        bkgd(COLOR_PAIR(color.getAttribute()));
    };

    const auto update = [&] {
        clear();

        for (const auto &object : objects) {
            object.update();
        }

        if (border) {
            border->update();
        }

        refresh();
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