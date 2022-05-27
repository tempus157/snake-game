#include "../main.hpp"

Object title(const std::string &text, const ColorPair &color) {
    return createObject()
        .useObject(label(text, color))
        .done();
}
