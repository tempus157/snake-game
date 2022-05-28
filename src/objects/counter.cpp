#include "../main.hpp"

Object counter(const Property<std::string> &text) {
    static auto count = useState(0);
    static auto countText = useState("Counter here!");

    count.onChange([=](const int &before, const int &after) {
        countText = *text + std::to_string(*count);
    });

    onKeyPress(Key::Enter, [](const Key &key) {
        count = *count + 1;
    });

    return createObject()
        .useObject(label(countText, Vector(1, 2)))
        .done();
}
