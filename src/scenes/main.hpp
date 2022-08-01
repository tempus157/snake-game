#include "creact.h"

using Creact::Element;
using Creact::Vector;

Element mainScene() {
    return [](const Vector &pos) {
        title("Hello, world!")(pos);
    };
}
