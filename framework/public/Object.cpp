#include "Object.hpp"

#include <ncurses.h>

Object::Object(const std::function<void(const Vector2 &)> &update) : update(update) {}

Object::Object(const std::vector<const Object> &objects)
    : update([=](const Vector2 &origin) {
          const auto cursor = Vector2(getcurx(stdscr), getcury(stdscr));
          for (auto object : objects) {
              object.update(cursor);
          }
      }) {}
