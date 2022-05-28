#ifndef __FRAMEWORK_INPUT__
#define __FRAMEWORK_INPUT__

#include <functional>
#include <map>
#include <vector>

enum class Key {
    Any,
    Error,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Number0,
    Number1,
    Number2,
    Number3,
    Number4,
    Number5,
    Number6,
    Number7,
    Number8,
    Number9,
    Backtick,
    Hyphen,
    Equal,
    LeftBracket,
    RightBracket,
    Backslash,
    Semicolon,
    Apostrophe,
    Comma,
    Period,
    Slash,
    Space,
    Escape,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    Tab,
    Backspace,
    Enter,
    Insert,
    Delete,
    Home,
    End,
    PageUp,
    PageDown,
    UpArrow,
    DownArrow,
    LeftArrow,
    RightArrow,
};

class Input final {
public:
    Input() = delete;
    Input(const Input &) = delete;
    Input(Input &&) = delete;

    Input &operator=(const Input &) = delete;
    Input &operator=(Input &&) = delete;

    static void onKeyPress(const Key &key, const std::function<void(const Key &)> &callback);
    static void notifyKeyPress(const Key &key);
    static void mount();
    static Key readKey();

private:
    static std::map<const Key, std::vector<const std::function<void(const Key &)>>> keyPressCallbacks;
};

#endif
