#include "../main.hpp"

Scene myScene() {
    auto titleText = Property<string>("Do you see this?");
    auto asyncID = Property<int>();

    asyncCall(1000, [=]() mutable {
        titleText.set("Hello, world!");
    });

    asyncID.set(asyncLoop(1000, [=]() mutable {
        soundBeep();
    }));

    onKeyPress(Key::Q, [] {
        changeScene("sub");
    });

    onKeyPress(Key::Space, [=]() mutable {
        const auto text = readLine();
        titleText.set(text);
    });

    onDestroy([=] {
        clearAsync(*asyncID);
    });

    return Object({
        $goto(Vector2(1, 1)),
        border('*', Vector2(40, 20)),
        $goto(Vector2(10, 5)),
        box('s', Vector2(10, 5), Color::Cyan, Color::Cyan),
        $goto(Vector2(0, 0)),
        label(titleText, Color::Red, Color::Blue),
        $goto(Vector2(3, 2)),
        counter("Count: "),
    });
}
