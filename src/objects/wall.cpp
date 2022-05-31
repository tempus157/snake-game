#include "../main.hpp"

Object wall(const Property<std::set<std::pair<int, int>>> &position) {
    return Object({
        $for(position, [](const std::pair<int, int> &item, int i) {
            return $union({
                $goto(Vector2(item.first, item.second)),
                label("ㅁ"),
            });
        }),
    });
}