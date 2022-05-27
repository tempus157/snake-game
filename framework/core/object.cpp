#include "object.hpp"

Object::Object(const std::function<void()> &update, const std::function<void()> &destroy)
    : update(update), destroy(destroy) {}

ObjectData &ObjectData::useObject(const Object &object) {
    objects.push_back(object);
    return *this;
}

Object ObjectData::done() const {
    const auto update = [&] {
        for (const auto &object : objects) {
            object.update();
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
