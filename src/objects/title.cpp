#include "../main.hpp"

Object title(const string &text, const Optional<ColorPair> &color)
{
    return createObject()
        .use(label(text, color))
        .done();
}
