#ifndef __FRAMEWORK_SCENE__
#define __FRAMEWORK_SCENE__

#include "Object.hpp"

#include <functional>
#include <vector>

class Scene final {
public:
    std::function<void()> update;
    Scene();
    Scene(const std::vector<const Object> &objects);
};

using SceneFunction = std::function<Scene()>;

#endif