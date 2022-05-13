#ifndef __FRAMEWORK_UTIL_COLOR__
#define __FRAMEWORK_UTIL_COLOR__

enum class Color
{
    Black = 0,
    Red = 1,
    Green = 2,
    Yellow = 3,
    Blue = 4,
    Magenta = 5,
    Cyan = 6,
    White = 7
};

struct ColorPair
{
public:
    Color foreground = Color::White;
    Color background = Color::Black;

    ColorPair();
    ColorPair(Color foreground, Color background);
    short getAttribute();
};

#endif
