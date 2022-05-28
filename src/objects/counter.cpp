#include "../main.hpp"

Object counter(const State<std::string> &text) {
    static auto count = useState(0);
    static auto countText = useState("Counter here!");

    useEffect(
        [=] {
            countText = *text + std::to_string(*count);
        },
        text, count);

    onKeyPress(Key::UpArrow, [](const Key &key) {
        count = *count + 1;
    });

    onKeyPress(Key::DownArrow, [](const Key &key) {
        count = *count - 1;
    });

    return createObject()
        .useObject(label(countText, Vector(1, 2)))
        .done();
}
