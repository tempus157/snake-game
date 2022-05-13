#include "color.hpp"

ColorPair::ColorPair() {}
ColorPair::ColorPair(Color foreground, Color background) : foreground(foreground), background(background) {}

short ColorPair::getAttribute()
{
    auto lhs = static_cast<unsigned int>(foreground) * 10;
    auto rhs = static_cast<unsigned int>(background);
    return lhs + rhs;
}