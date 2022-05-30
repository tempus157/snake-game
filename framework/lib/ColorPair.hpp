#ifndef __FRAMEWORK_COLOR_PAIR__
#define __FRAMEWORK_COLOR_PAIR__

#include "Color.hpp"

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
