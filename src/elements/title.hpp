#include "creact.h"

using Creact::Element;
using Creact::label;
using Creact::useState;
using Creact::Vector;

Element title(const std::string &text) {
    const auto count = useState(0);

    return [=](const Vector &pos) {
        label(count.value < 5 ? std::to_string(count.value) : "TOO MUCH")(pos);
    };
}
