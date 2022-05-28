#include "../main.hpp"

Object counter(const Property<std::string> &text) {
    static auto count = 0;
    static auto countStr = useState(*text + std::to_string(count));
    static auto log = useState("Log here!");

    countStr.onChange([](const std::string &before, const std::string &after) {
        log = before + ", " + after;
    });

    onKeyPress(Key::Enter, [=](const Key &key) {
        count++;
        countStr = *text + std::to_string(count);
    });

    return createObject()
        .useObject(label(countStr, Vector(1, 2)))
        .useObject(label(log, Vector(1, 3)))
        .done();
}
