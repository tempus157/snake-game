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
    static Object &create();
    Object &setText(std::string text);
    Object &setPosition(Vector position);
    Object &setPosition(int x, int y);

private:
    std::string text;
    Vector position;
};

class Window
{
public:
    static Window &create();
    Window &setScale(Vector scale);
    Window &setScale(int x, int y);
    Window &useObject(Object const &object);

private:
    std::vector<Object const &> objects;
};

class App
{
public:
    static App &create();
    App &useWindow(std::function<Window()> window);
    int execute();
};

#endif
