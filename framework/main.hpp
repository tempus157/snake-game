#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./public/App.hpp"
#include "./public/Color.hpp"
#include "./public/Key.hpp"
#include "./public/Object.hpp"
#include "./public/Property.hpp"
#include "./public/PropertyEvent.hpp"
#include "./public/Scene.hpp"
#include "./public/Vector.hpp"

#include <functional>
#include <memory>
#include <string>

using std::string;
using Callback = std::function<void()>;

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

void changeScene(const string &name);
void quitApp();
void soundBeep();
string readLine();

unsigned int setInterval(const Callback &callback, unsigned int delay);
void clearInterval(unsigned int id);

void mountObject(const string &name);
void destroyObject(const string &name);

void onKeyPress(const Key &key, const Callback &callback);

template <typename T>
void onUpdate(const Callback &callback, const Property<T> &dep) {
    PropertyEvent::onUpdate(dep, callback);
}

template <typename TDep, typename... TDeps>
void onUpdate(const Callback &callback,
    const Property<TDep> &dep, const Property<TDeps> &...deps) {
    PropertyEvent::onUpdate(dep, callback);
    onUpdate(callback, deps...);
}

#endif
