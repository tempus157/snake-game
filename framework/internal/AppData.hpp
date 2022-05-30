#ifndef __FRAMEWORK_APP_DATA__
#define __FRAMEWORK_APP_DATA__

#include "../core/Object.hpp"
#include "../lib/Vector.hpp"

#include <memory>
#include <vector>

class AppData final {
public:
    static AppData &getInstance();

    Vector2 getScale() const;
    void setScale(const Vector2 &scale);
    void useObject(const Object &object);
    void quit();

    void mount();
    void update() const;
    void receiveInput() const;
    void destroy() const;

private:
    bool progress = true;
    Vector2 scale = Vector2(-1, -1);
    std::vector<const Object> objects;
};

#endif
