#include "../main.hpp"

Object title(const std::string &text, const ColorPair &color) {
    return createObject()
        .use(label(text, color))
        .done();
}
