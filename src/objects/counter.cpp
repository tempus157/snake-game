#include "../main.hpp"

Object counter(const Property<std::string> &text) {
    auto count = useProperty(0);
    auto countText = useProperty("Counter here!");
    auto isCountEven = useProperty(*count % 2 == 0);
    auto countList = useProperty<std::vector<int>>();

    onUpdate(text, count, [=]() mutable {
        countText = *text + std::to_string(*count);
    });

    onUpdate(count, [=]() mutable {
        isCountEven = *count % 2 == 0;
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        count = *count + 1;
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        count = *count - 1;
    });

    onKeyPress(Key::Enter, [=]() mutable {
        countList->push_back(*count);
        countList = *countList;
    });

    return Object({
        label(countText),
        $goto(Vector2(2, 1)),
        $if(isCountEven, label("Even"), label("Odd")),
        $goto(Vector2(2, 2)),
        $for(countList, [](const int &item) {
            return label(std::to_string(item));
        }),
    });
}
