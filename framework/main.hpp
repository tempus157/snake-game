#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./public/App.hpp"
#include "./public/Color.hpp"
#include "./public/Key.hpp"
#include "./public/LifeCycle.hpp"
#include "./public/Object.hpp"
#include "./public/Property.hpp"
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
Object $union(const std::vector<const Object> &objects);
Object $if(const Property<bool> &condition, const Object &ifTrue);
Object $if(const Property<bool> &condition, const Object &ifTrue, const Object &ifFalse);

template <typename TCollection, typename TCallback>
Object $for(const Property<TCollection> &collection, const TCallback &callback) {
    auto update = [=](const Vector2 &origin) {
        auto i = 0;
        for (const auto &item : *collection) {
            callback(item, i).update(origin);
            i++;
        }
    };

    return Object(update);
}

template <typename TCollection, typename TCallback>
Object $for(const TCollection &collection, const TCallback &callback) {
    auto update = [=](const Vector2 &origin) {
        auto i = 0;
        for (const auto &item : collection) {
            callback(item, i).update(origin);
            i++;
        }
    };

    return Object(update);
}

void changeScene(const string &name);
void quitApp();
void soundBeep();
string readLine();

int asyncCall(int delay, const Callback &callback);
int asyncLoop(int delay, const Callback &callback);
void clearAsync(int id);

void onKeyPress(const Key &key, const Callback &callback);

template <typename T>
void onUpdate(const Callback &callback, const Property<T> &dep) {
    LifeCycle::onUpdate(dep, callback);
}

template <typename TDep, typename... TDeps>
void onUpdate(const Callback &callback,
    const Property<TDep> &dep, const Property<TDeps> &...deps) {
    LifeCycle::onUpdate(dep, callback);
    onUpdate(callback, deps...);
}

#endif
