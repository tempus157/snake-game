#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/property.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

ObjectData &createObject();
WindowData &createWindow(const Vector &position, const Vector &scale);
App &createApp();
Object label(const Property<std::string> &text);
Object label(const Property<std::string> &text, const Property<Vector> &position);
Object label(const Property<std::string> &text, const Property<ColorPair> &color);

Object label(const Property<std::string> &text, const Property<Vector> &position,
    const Property<ColorPair> &color);

Object $goto(const Property<Vector> &position);
Object $goto(const Property<int> &x, const Property<int> &y);

Object $if(const Property<bool> &condition, const Object &ifTrue);
Object $if(const Property<bool> &condition, const Object &ifTrue, const Object &ifFalse);

template <typename TCollection, typename TCallback>
Object $for(const Property<TCollection> &collection, const TCallback &callback) {
    auto update = [=](WINDOW *window) {
        for (const auto &item : *collection) {
            callback(item).update(window);
        }
    };

    return Object(update, [] {});
}

template <typename T>
Property<T> useProperty() {
    return Property<T>();
}

template <typename T>
Property<T> useProperty(const T &value) {
    return Property<T>(value);
}

Property<std::string> useProperty(const char *value);

void quitApp();
std::string readLine();
void onKeyPress(const Key &key, const std::function<void()> &callback);

#pragma region onUpdate

template <typename T1>
void onUpdate(const Property<T1> &dep1, const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
}

template <typename T1, typename T2>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2,
    const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
}

template <typename T1, typename T2, typename T3>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2, const Property<T3> &dep3,
    const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
}

template <typename T1, typename T2, typename T3, typename T4>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2,
    const Property<T3> &dep3, const Property<T4> &dep4,
    const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
    Property<T4>::onUpdate(dep4, callback);
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2,
    const Property<T3> &dep3, const Property<T4> &dep4, const Property<T5> &dep5,
    const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
    Property<T4>::onUpdate(dep4, callback);
    Property<T5>::onUpdate(dep5, callback);
}

template <typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2, const Property<T3> &dep3,
    const Property<T4> &dep4, const Property<T5> &dep5,
    const Property<T6> &dep6, const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
    Property<T4>::onUpdate(dep4, callback);
    Property<T5>::onUpdate(dep5, callback);
    Property<T6>::onUpdate(dep6, callback);
}

template <typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6, typename T7>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2, const Property<T3> &dep3,
    const Property<T4> &dep4, const Property<T5> &dep5, const Property<T6> &dep6,
    const Property<T7> &dep7, const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
    Property<T4>::onUpdate(dep4, callback);
    Property<T5>::onUpdate(dep5, callback);
    Property<T6>::onUpdate(dep6, callback);
    Property<T7>::onUpdate(dep7, callback);
}

template <typename T1, typename T2, typename T3, typename T4,
    typename T5, typename T6, typename T7, typename T8>
void onUpdate(const Property<T1> &dep1, const Property<T2> &dep2,
    const Property<T3> &dep3, const Property<T4> &dep4, const Property<T5> &dep5,
    const Property<T6> &dep6, const Property<T7> &dep7, const Property<T8> &dep8,
    const std::function<void()> &callback) {
    Property<T1>::onUpdate(dep1, callback);
    Property<T2>::onUpdate(dep2, callback);
    Property<T3>::onUpdate(dep3, callback);
    Property<T4>::onUpdate(dep4, callback);
    Property<T5>::onUpdate(dep5, callback);
    Property<T6>::onUpdate(dep6, callback);
    Property<T7>::onUpdate(dep7, callback);
    Property<T8>::onUpdate(dep8, callback);
}

#pragma endregion

#endif
