#ifndef __FRAMEWORK_COLOR__
#define __FRAMEWORK_COLOR__

enum class Color {
    Black = 0,
    Red = 1,
    Green = 2,
    Yellow = 3,
    Blue = 4,
    Magenta = 5,
    Cyan = 6,
    White = 7,
};

class ColorPair final {
public:
    Color foreground = Color::White;
    Color background = Color::Black;

    ColorPair();
    ColorPair(const Color &foreground, const Color &background);

    static void mount();
    short getAttribute() const;
};

#endif
