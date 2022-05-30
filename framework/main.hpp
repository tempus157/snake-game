#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/App.hpp"
#include "./core/Object.hpp"
#include "./core/Property.hpp"
#include "./core/PropertyEvent.hpp"
#include "./lib/Color.hpp"
#include "./lib/Key.hpp"
#include "./lib/Vector.hpp"

#include <functional>
#include <memory>
#include <string>

using std::string;

Object label(const Property<string> &text);
Object label(const Property<string> &text,
    const Property<Color> &foreground, const Property<Color> &background);

Object box(const Property<char> &ch, const Property<Vector2> &scale);
Object box(const Property<char> &ch, const Property<Vector2> &scale,
    const Property<Color> &foreground, const Property<Color> &background);

Object border(const Property<char> &ch, const Property<Vector2> &scale);
Object border(const Property<char> &ch, const Property<Vector2> &scale,
    const Property<Color> &foreground, const Property<Color> &background);

Object $goto(const Property<Vector2> &position);
Object $if(const Property<bool> &condition, const Object &ifTrue);
Object $if(const Property<bool> &condition, const Object &ifTrue, const Object &ifFalse);

template <typename TCollection, typename TCallback>
Object $for(const Property<TCollection> &collection, const TCallback &callback) {
    auto update = [=](const Vector2 &origin) {
        for (const auto &item : *collection) {
            callback(item).update(origin);
        }
    };

    return Object(update);
}

void quitApp();
void soundBeep();
std::string readLine();
void onKeyPress(const Key &key, const std::function<void()> &callback);

template <typename T>
void onUpdate(const std::function<void()> &callback, const Property<T> &dep) {
    PropertyEvent::onUpdate(dep, callback);
}

template <typename TDep, typename... TDeps>
void onUpdate(const std::function<void()> &callback,
    const Property<TDep> &dep, const Property<TDeps> &...deps) {
    PropertyEvent::onUpdate(dep, callback);
    onUpdate(callback, deps...);
}

#endif
