#include "../main.hpp"

Object counter(const Property<string> &text) {
    auto count = Property<int>(0);
    auto countText = Property<string>("Counter here!");
    auto isCountEven = Property<bool>(*count % 2 == 0);
    auto countList = Property<std::vector<int>>();

    onUpdate([=]() mutable {
        countText.set(*text + std::to_string(*count));
    },
        text, count);

    onUpdate([=]() mutable {
        isCountEven.set(*count % 2 == 0);
    },
        count);

    onKeyPress(Key::UpArrow, [=]() mutable {
        count.set(*count + 1);
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        count.set(*count - 1);
    });

    onKeyPress(Key::Enter, [=]() mutable {
        countList->push_back(*count);
        countList.set(*countList);
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
