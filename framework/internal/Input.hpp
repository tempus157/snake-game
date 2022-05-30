#ifndef __FRAMEWORK_INPUT__
#define __FRAMEWORK_INPUT__

#include "../lib/Key.hpp"

#include <functional>
#include <map>
#include <vector>

class Input final {
public:
    Input() = delete;
    Input(const Input &) = delete;
    Input(Input &&) = delete;
    Input &operator=(const Input &) = delete;
    Input &operator=(Input &&) = delete;

    static void onKeyPress(const Key &key, const std::function<void()> &callback);
    static void notifyKeyPress(const Key &key);
    static void mount();
    static Key readKey();

private:
    static std::map<const Key, std::vector<const std::function<void()>>> keyPressCallbacks;
};

#endif
