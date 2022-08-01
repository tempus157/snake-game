#include "creact.h"

using Creact::Element;
using Creact::label;
using Creact::Vector;

Element title(const std::string &text) {
    return [=](const Vector &pos) {
        label("Hello, world!")(pos);
    };
}
