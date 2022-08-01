#include "color.h"

#include <ncurses.h>

namespace InternalCreact {
    void mountColor() {
        start_color();

        for (auto foreground = 0; foreground < 8; foreground++) {
            for (auto background = 0; background < 8; background++) {
                const auto attribute = colorAttribute(
                    static_cast<Creact::Color>(foreground),
                    static_cast<Creact::Color>(background));
                init_pair(attribute, foreground, background);
            }
        }
    }

    void enableColor(const Creact::Color foreground,
        const Creact::Color background) {
        attron(COLOR_PAIR(colorAttribute(foreground, background)));
    }

    void disableColor(const Creact::Color foreground,
        const Creact::Color background) {
        attroff(COLOR_PAIR(colorAttribute(foreground, background)));
    }

    short colorAttribute(const Creact::Color foreground,
        const Creact::Color background) {
        auto const lhs = static_cast<int>(foreground) * 10;
        auto const rhs = static_cast<int>(background);
        return lhs + rhs;
    }
}
