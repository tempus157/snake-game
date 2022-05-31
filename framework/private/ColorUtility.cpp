#include "ColorUtility.hpp"

#include <ncurses.h>

void ColorUtility::mount() {
    start_color();

    for (auto foreground = 0; foreground < 8; foreground++) {
        for (auto background = 0; background < 8; background++) {
            const auto attribute = getAttribute(
                static_cast<Color>(foreground), static_cast<Color>(background));
            init_pair(attribute, foreground, background);
        }
    }
}

void ColorUtility::enableColor(const Color &foreground, const Color &background) {
    attron(COLOR_PAIR(getAttribute(foreground, background)));
}

void ColorUtility::disableColor(const Color &foreground, const Color &background) {
    attroff(COLOR_PAIR(getAttribute(foreground, background)));
}

short ColorUtility::getAttribute(const Color &foreground, const Color &background) {
    auto const lhs = static_cast<int>(foreground) * 10;
    auto const rhs = static_cast<int>(background);
    return lhs + rhs;
}
