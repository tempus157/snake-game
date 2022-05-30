#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/App.hpp"
#include "./core/Object.hpp"
#include "./core/Property.hpp"
#include "./lib/Color.hpp"
#include "./lib/Key.hpp"
#include "./lib/Vector.hpp"

#include <functional>
#include <memory>
#include <string>

// 1. 글자만 있는 패널
// 2. 글자, 색깔 있는 패널

Object panel(const Property<char> &ch, const Property<Vector2> &scale);
Object panel(const Property<char> &ch, const Property<Vector2> &scale,
    const Property<Color> &foreground, const Property<Color> &background);

Object label(const Property<std::string> &text);
Object label(const Property<std::string> &text,
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

template <typename T>
Property<T> useProperty() {
    return Property<T>();
}

template <typename T, T... Is>
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
