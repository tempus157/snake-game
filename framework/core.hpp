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

enum class Color
{
    Black = 0,
    Red = 1,
    Green = 2,
    Yellow = 3,
    Blue = 4,
    Magenta = 5,
    Cyan = 6,
    White = 7,
};

struct ColorPair
{
public:
    Color foreground = Color::White;
    Color background = Color::Black;

    ColorPair();
    ColorPair(Color foreground, Color background);
    short getAttribute();
};

template <typename T>
struct Optional
{
public:
    T value;
    bool hasValue;

    Optional() : hasValue(false) {}
    Optional(std::nullptr_t value) : Optional() {}
    Optional(T value) : value(value), hasValue(true) {}

    Optional<T> &operator=(std::nullptr_t value)
    {
        hasValue = false;
        return *this;
    }

    Optional<T> &operator=(T value)
    {
        this->value = value;
        this->hasValue = true;
        return *this;
    }
};

class Object
{
public:
    static Object *create();
    Object *setText(std::string text);
    Object *setPosition(Vector position);
    Object *setPosition(int x, int y);
    Object *setColor(ColorPair color);
    Object *setColor(Color foreground, Color background);

    void render();

private:
    std::string text;
    Vector position;
    Optional<ColorPair> color;
};

class Window
{
public:
    static Window *create();
    Window *setScale(Vector scale);
    Window *setScale(int x, int y);
    Window *setColor(ColorPair color);
    Window *setColor(Color foreground, Color background);
    Window *useObject(Object *object);

    void init();
    void render();
    void release();

private:
    std::vector<Object *> objects;
    Vector scale;
    ColorPair color;
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
    void initColors();
    void updateWindows();
    void renderWindows();
    void releaseWindows();
};

#endif
