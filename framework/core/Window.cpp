#include "Window.hpp"

#include <memory>

Window::Window(const Vector &position,
    const Vector &scale,
    const std::vector<const Object> &objects)
    : mount([=] {
          window = newwin(scale.y, scale.x, position.y, position.x);
      }),
      update([=] {
          wclear(window);
          for (const auto &object : objects) {
              object.update(window);
          }
          wrefresh(window);
      }),
      destroy([=] {
          endwin();
      }) {}
