#ifndef __FRAMEWORK_APP_DATA__
#define __FRAMEWORK_APP_DATA__

#include "../public/Object.hpp"
#include "../public/Scene.hpp"
#include "../public/Vector.hpp"

#include <map>

class AppData final {
public:
    static AppData &getInstance();

    void setScale(const Vector2 &scale);
    void useScene(const std::string &name, const SceneFunction &scene);
    void changeScene(const std::string &name);
    void quit();

    void mount();
    void update() const;
    void receiveInput() const;

private:
    Vector2 scale = Vector2(-1, -1);
    std::map<const std::string, SceneFunction> scenes;
    Scene activeScene;
    AppData();
};

#endif
