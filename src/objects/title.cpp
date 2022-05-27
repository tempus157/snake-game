#include "../main.hpp"

Object title(string text, Optional<ColorPair> color)
{
    return createObject()
        .use(label(text, color))
        .done();
}
