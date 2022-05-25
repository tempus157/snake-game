#include "border.hpp"

Border::Border() : Border('+') {}

Border::Border(unsigned int const character) : left(character), right(character),
                                               top(character), bottom(character),
                                               topLeft(character), topRight(character),
                                               bottomLeft(character), bottomRight(character) {}
