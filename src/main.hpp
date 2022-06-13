#include "../framework/main.hpp"
#include "./libs/map.hpp"

Scene introScene();
Scene gameScene();
Scene resultScene();
Scene errorScene();

Object wall(const Property<Map> &map);
Object snake(Property<Map> &map);
