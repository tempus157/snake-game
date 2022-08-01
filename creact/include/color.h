#ifndef __CREACT_COLOR__
#define __CREACT_COLOR__

namespace Creact {
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
}

namespace InternalCreact {
    void mountColor();
    void enableColor(const Creact::Color foreground,
        const Creact::Color background);
    void disableColor(const Creact::Color foreground,
        const Creact::Color background);
    short colorAttribute(const Creact::Color foreground,
        const Creact::Color background);
}

#endif
