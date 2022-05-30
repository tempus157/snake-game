#include "Window.hpp"

#include "../internal/WindowData.hpp"

Window::Window() : data(std::make_shared<WindowData>()) {}

Window &Window::setPosition(const Vector &position) {
    data->setPosition(position);
    return *this;
}

Window &Window::setScale(const Vector &scale) {
    data->setScale(scale);
    return *this;
}

Window &Window::setColor(const ColorPair &color) {
    data->setColor(color);
    return *this;
}

Window &Window::setBorderCh(char ch) {
    data->setBorderCh(ch);
    return *this;
}

Window &Window::setBorderColor(const ColorPair &color) {
    data->setBorderColor(color);
    return *this;
}

Window &Window::useObjects(const std::vector<const Object> &objects) {
    data->useObjects(objects);
    return *this;
}
