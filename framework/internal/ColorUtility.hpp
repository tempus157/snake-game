#ifndef __FRAMEWORK_COLOR_PAIR__
#define __FRAMEWORK_COLOR_PAIR__

#include "../lib/Color.hpp"

class ColorUtility final {
public:
    ColorUtility() = delete;
    ColorUtility(const ColorUtility &) = delete;
    ColorUtility(ColorUtility &&) = delete;
    ColorUtility &operator=(const ColorUtility &) = delete;
    ColorUtility &operator=(ColorUtility &&) = delete;

    static void mount();
    static short getAttribute(const Color &foreground, const Color &background);
};

#endif
