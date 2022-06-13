#include "../main.hpp"

Object wall(const Property<Map> &map) {
    return Object({
        $for(map->wall, [=](const std::pair<int, int> &item, int i) {
            return $union({
                $goto(Vector2(item.first, item.second)),
                label("ㅁ", Color::Blue, Color::Black),
            });
        }),
        $for(map->immuneWall, [=](const std::pair<int, int> &item, int i) {
            return $union({
                $goto(Vector2(item.first, item.second)),
                label("ㅍ", Color::Blue, Color::Black),
            });
        }),
    });
}