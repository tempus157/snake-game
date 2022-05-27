#ifndef __FRAMEWORK_CORE_WINDOW__
#define __FRAMEWORK_CORE_WINDOW__

#include "border.hpp"
#include "object.hpp"

#include "../utils/color.hpp"
#include "../utils/optional.hpp"
#include "../utils/vector.hpp"

#include <vector>
#include <functional>
#include <ncurses.h>

class Window
{
public:
    class Hooks
    {
    public:
        Hooks(Window *window);
        ~Hooks();
        void init();
        void start() const;
        void update() const;
        void render() const;

    private:
        Window *window;
        void renderBorder(const Border *border) const;
        void renderObjects() const;
    };

    static Window *create();

    Window *setScale(const Vector &scale);
    Window *setScale(int x, int y);
    Window *setColor(ColorPair const &color);
    Window *setColor(const Color &foreground, const Color &background);
    Window *setBorder(const Border *border);
    Window *useObject(const Object *object);
    Window *onStart(const std::function<void()> callback);

private:
    Window();
    ~Window();

    const WINDOW *window;
    Vector scale;
    ColorPair color;
    Optional<const Border *> border;

    std::vector<const Object *> objects;
    std::vector<const std::function<void()>> startCallbacks;
};

#endif
