#include "object.hpp"

Object::Object(const std::function<void(WINDOW *)> &update,
    const std::function<void()> &destroy)
    : update(update), destroy(destroy) {}

ObjectData &ObjectData::useObject(const Object &object) {
    objects.push_back(object);
    return *this;
}

Object ObjectData::done() const {
    const auto update = [&](WINDOW *window) {
        for (const auto &object : objects) {
            object.update(window);
        }
    };

    const auto destroy = [&] {
        for (const auto &object : objects) {
            object.destroy();
        }
        delete this;
    };

    return Object(update, destroy);
}
