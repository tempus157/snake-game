#include "Object.hpp"

Object::Object(const std::function<void(WINDOW *)> &update,
    const std::function<void()> &destroy)
    : update(update), destroy(destroy) {}
