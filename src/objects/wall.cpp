#include "objects.h"

Object wall(const Property<std::set<std::pair<int, int>>> &position,
    const Property<std::set<std::pair<int, int>>> &immunePosition) {
    return {{
        $for(position, [=](const std::pair<int, int> &item, int i) {
            return $union({
                $goto(Vector2(item.first, item.second)),
                label("ㅁ", Color::Blue, Color::Black),
            });
        }),
        $for(immunePosition, [=](const std::pair<int, int> &item, int i) {
            return $union({
                $goto(Vector2(item.first, item.second)),
                label("ㅍ", Color::Blue, Color::Black),
            });
        }),
    }};
}