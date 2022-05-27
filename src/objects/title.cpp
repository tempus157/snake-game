#include "../main.hpp"

Object title(const string &text, const ColorPair &color)
{
    return createObject()
        .use(label(text, color))
        .done();
}
