#ifndef __FRAMEWORK_COLOR_PAIR__
#define __FRAMEWORK_COLOR_PAIR__

#include "../public/Color.hpp"

class ColorUtility final {
public:
    ColorUtility() = delete;
    ColorUtility(const ColorUtility &) = delete;
    ColorUtility(ColorUtility &&) = delete;
    ColorUtility &operator=(const ColorUtility &) = delete;
    ColorUtility &operator=(ColorUtility &&) = delete;

    static void mount();
    static void enableColor(const Color &foreground, const Color &background);
    static void disableColor(const Color &foreground, const Color &background);

private:
    static short getAttribute(const Color &foreground, const Color &background);
};

#endif
