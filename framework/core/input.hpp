#ifndef __FRAMEWORK_CORE_INPUT__
#define __FRAMEWORK_CORE_INPUT__

#include <functional>

enum class Key : char
{
    None = '\0',
    Number0 = '0',
    Number1 = '1',
    Number2 = '2',
    Number3 = '3',
    Number4 = '4',
    Number5 = '5',
    Number6 = '6',
    Number7 = '7',
    Number8 = '8',
    Number9 = '9',
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H',
    I = 'I',
    J = 'J',
    K = 'K',
    L = 'L',
    M = 'M',
    N = 'N',
    O = 'O',
    P = 'P',
    Q = 'Q',
    R = 'R',
    S = 'S',
    T = 'T',
    U = 'U',
    V = 'V',
    W = 'W',
    X = 'X',
    Y = 'Y',
    Z = 'Z',
    Backtick = '~',
    Hyphen = '-',
    Equal = '=',
    LeftBracket = '[',
    RightBracket = ']',
    Backslash = '\\',
    Semicolon = ';',
    Quote = '\'',
    Comma = ',',
    Period = '.',
    Slash = '/',
    Space = ' ',
};

class Input
{
public:
    static void readKey();
    static bool keyPressed();
    static Key currentKey();
    static void addListener(Key key, std::function<void(Key)> func);

private:
    static Key key;
    Input() {}
};

#endif
