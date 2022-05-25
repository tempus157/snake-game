#ifndef __FRAMEWORK_CORE__
#define __FRAMEWORK_CORE__

#include <string>
#include <vector>
#include <functional>

struct Vector
{
public:
    int x = 0;
    int y = 0;

    static const Vector zero;
    static const Vector one;
    static const Vector up;
    static const Vector down;
    static const Vector left;
    static const Vector right;

    Vector();
    Vector(int x, int y);
};

class Object
{
public:
    static Object *create();
    Object *setText(std::string text);
    Object *setPosition(Vector position);
    Object *setPosition(int x, int y);

    void render();

private:
    std::string text;
    Vector position;
};

class Window
{
public:
    static Window *create();
    Window *setScale(Vector scale);
    Window *setScale(int x, int y);
    Window *useObject(Object *object);

    void init();
    void render();
    void release();

private:
    std::vector<Object *> objects;
    Vector scale;
};

class App
{
public:
    static App *create();
    App *useWindow(Window *window);
    int execute();

private:
    static bool progress;
    std::vector<Window *> windows;

    App();
    ~App();

    void initWindows();
    void updateWindows();
    void renderWindows();
    void releaseWindows();
};

#endif
