#include "../main.hpp"

Object counter() {
    static auto count = 0;
    static auto countStr = useState<std::string>("0");

    onKeyPress(Key::Enter, [&](Key key) {
        count++;
        countStr.set(std::to_string(count));
    });

    return createObject()
        .useObject(label(countStr.get(), Vector(1, 2)))
        .done();
}
