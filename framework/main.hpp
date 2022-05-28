#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/state.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

template <typename T>
State<T> useState() {
    return State<T>();
}

template <typename T>
State<T> useState(const T &value) {
    return State<T>(value);
}

State<std::string> useState(const char *value);

template <typename T1>
void onUpdate(const State<T1> &dep1,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
}

template <typename T1, typename T2>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
}

template <typename T1, typename T2, typename T3>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2, const State<T3> &dep3,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
}

template <typename T1, typename T2, typename T3, typename T4>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2,
    const State<T3> &dep3, const State<T4> &dep4,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
    State<T4>::onUpdate(dep4, callback);
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2,
    const State<T3> &dep3, const State<T4> &dep4, const State<T5> &dep5,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
    State<T4>::onUpdate(dep4, callback);
    State<T5>::onUpdate(dep5, callback);
}

template <typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2, const State<T3> &dep3,
    const State<T4> &dep4, const State<T5> &dep5,
    const State<T6> &dep6, const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
    State<T4>::onUpdate(dep4, callback);
    State<T5>::onUpdate(dep5, callback);
    State<T6>::onUpdate(dep6, callback);
}

template <typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6, typename T7>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2, const State<T3> &dep3,
    const State<T4> &dep4, const State<T5> &dep5, const State<T6> &dep6,
    const State<T7> &dep7, const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
    State<T4>::onUpdate(dep4, callback);
    State<T5>::onUpdate(dep5, callback);
    State<T6>::onUpdate(dep6, callback);
    State<T7>::onUpdate(dep7, callback);
}

template <typename T1, typename T2, typename T3, typename T4,
    typename T5, typename T6, typename T7, typename T8>
void onUpdate(const State<T1> &dep1, const State<T2> &dep2,
    const State<T3> &dep3, const State<T4> &dep4, const State<T5> &dep5,
    const State<T6> &dep6, const State<T7> &dep7, const State<T8> &dep8,
    const std::function<void()> &callback) {
    State<T1>::onUpdate(dep1, callback);
    State<T2>::onUpdate(dep2, callback);
    State<T3>::onUpdate(dep3, callback);
    State<T4>::onUpdate(dep4, callback);
    State<T5>::onUpdate(dep5, callback);
    State<T6>::onUpdate(dep6, callback);
    State<T7>::onUpdate(dep7, callback);
    State<T8>::onUpdate(dep8, callback);
}

void quitApp();
void onKeyPress(const Key &key, const std::function<void(const Key &)> &callback);

Object label(const State<std::string> &text);
Object label(const State<std::string> &text, const State<Vector> &position);
Object label(const State<std::string> &text, const State<ColorPair> &color);

Object label(const State<std::string> &text, const State<Vector> &position,
    const State<ColorPair> &color);

#endif
