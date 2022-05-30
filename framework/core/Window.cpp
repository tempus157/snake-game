#include "Window.hpp"

#include "../internal/WindowData.hpp"

Window::Window(const std::vector<const Object> &objects)
    : data(std::make_shared<WindowData>()) {
    data->useObjects(objects);
}
