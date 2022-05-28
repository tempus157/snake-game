#include "../main.hpp"

Object counter(const State<std::string> &text) {
    static auto count = useState(0);
    static auto countText = useState("Counter here!");

    onUpdate(text, count, [=] {
        countText = *text + std::to_string(*count);
    });

    onKeyPress(Key::UpArrow, [] {
        count = *count + 1;
    });

    onKeyPress(Key::DownArrow, [] {
        count = *count - 1;
    });

    return createObject()
        .useObject(label(countText, Vector(1, 2)))
        .done();
}
