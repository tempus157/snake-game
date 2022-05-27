#include "color.hpp"
#include <ncurses.h>

ColorPair::ColorPair() {}

ColorPair::ColorPair(const Color &foreground, const Color &background)
    : foreground(foreground), background(background) {}

short ColorPair::getAttribute() const
{
    auto const lhs = static_cast<int>(foreground) * 10;
    auto const rhs = static_cast<int>(background);
    return lhs + rhs;
}

void ColorPair::mount()
{
    start_color();
    ColorPair color;

    for (auto foreground = 0; foreground < 8; foreground++)
    {
        for (auto background = 0; background < 8; background++)
        {
            color.foreground = static_cast<Color>(foreground);
            color.background = static_cast<Color>(background);
            init_pair(color.getAttribute(), foreground, background);
        }
    }
}
