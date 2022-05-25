#include "color.hpp"

ColorPair::ColorPair() {}

ColorPair::ColorPair(Color foreground, Color background)
    : foreground(foreground), background(background) {}

short ColorPair::getAttribute() const
{
    auto lhs = static_cast<int>(foreground) * 10;
    auto rhs = static_cast<int>(background);
    return lhs + rhs;
}