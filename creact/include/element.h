#ifndef __CREACT_ELEMENT__
#define __CREACT_ELEMENT__

#include <functional>
#include <string>

#include "color.h"
#include "vector.h"

namespace Creact {
    using Element = std::function<void(const Vector &)>;

    Element label(const std::string &text);
    Element label(const std::string &text,
        Color foreground, Color background);

    Element box(const char ch, const Vector &scale);
    Element box(const char ch, const Vector &scale,
        Color foreground, Color background);

    Element border(const char ch, const Vector &scale);
    Element border(const char ch, const Vector &scale,
        Color foreground, Color background);
}

#endif
