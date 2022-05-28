#include "../main.hpp"

Object counter(const Property<std::string> &text) {
    auto count = useProperty(0);
    auto countText = useProperty("Counter here!");

    onUpdate(text, count, [=]() mutable {
        countText = *text + std::to_string(*count);
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        count = *count + 1;
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        count = *count - 1;
    });

    return createObject()
        .useObject(label(countText, Vector(1, 2)))
        .done();
}
