#ifndef __FRAMEWORK_SCENE__
#define __FRAMEWORK_SCENE__

#include "Object.hpp"

#include <functional>
#include <vector>

class Scene;
using SceneFunction = std::function<Scene()>;

class Scene final {
public:
    std::function<void()> mount;
    std::function<void()> update;
    std::function<void()> destroy;

    Scene();
    Scene(const Object &object);
};

#endif