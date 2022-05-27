#ifndef __FRAMEWORK_INPUT__
#define __FRAMEWORK_INPUT__

#include <functional>
#include <map>
#include <vector>

enum class Key
{
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

class Input
{
public:
    static void addListener(const Key &key, const std::function<void()> &fn);
    void notifyListeners(const Key &key) const;
    void mount() const;
    Key readKey() const;

private:
    static std::map<Key, std::vector<std::function<void()>>> onKeyPress;
};

#endif
