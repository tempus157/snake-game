#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "../public/Vector.hpp"
#include "Object.hpp"
#include "Scene.hpp"

class App final {
public:
    App &setScale(const Vector2 &scale);
    App &useScene(const std::string &name, const SceneFunction &scene);
    int run(const std::string &sceneName) const;
};

#endif
