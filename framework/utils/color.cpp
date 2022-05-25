#include "color.hpp"

ColorPair::ColorPair() {}

ColorPair::ColorPair(Color const &foreground, Color const &background)
    : foreground(foreground), background(background) {}

short ColorPair::getAttribute() const
{
    auto const lhs = static_cast<int>(foreground) * 10;
    auto const rhs = static_cast<int>(background);
    return lhs + rhs;
}