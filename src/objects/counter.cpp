#include "../main.hpp"

Object counter() {
    static auto count = 0;
    static auto countStr = useProperty("0");

    onKeyPress(Key::Enter, [&](Key key) {
        count++;
        countStr = std::to_string(count);
    });

    return createObject()
        .useObject(label(countStr, Vector(1, 2)))
        .done();
}
