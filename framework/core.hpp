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

class IObject
{
public:
    virtual ~IObject() = default;
    virtual bool isActive() = 0;
    virtual void render() = 0;
};

class Label : public IObject
{
public:
    static Label *create();
    bool isActive() override;
    void render() override;

    Label *setText(std::string text);
    Label *setPosition(Vector position);
    Label *setPosition(int x, int y);
    Label *setColor(Optional<ColorPair> color);
    Label *setColor(Color foreground, Color background);

private:
    std::string text;
    Vector position;
    Optional<ColorPair> color;
};

class Border : public IObject
{
public:
    static Border *create();
    bool isActive() override;
    void render() override;

    Border *setCharacter(unsigned int character);
    Border *setLeft(unsigned int character);
    Border *setRight(unsigned int character);
    Border *setTop(unsigned int character);
    Border *setBottom(unsigned int character);
    Border *setTopLeft(unsigned int character);
    Border *setTopRight(unsigned int character);
    Border *setBottomLeft(unsigned int character);
    Border *setBottomRight(unsigned int character);
    Border *setColor(Optional<ColorPair> color);
    Border *setColor(Color foreground, Color background);

private:
    unsigned int left;
    unsigned int right;
    unsigned int top;
    unsigned int bottom;
    unsigned int topLeft;
    unsigned int topRight;
    unsigned int bottomLeft;
    unsigned int bottomRight;
    Optional<ColorPair> color;
};

class Window
{
public:
    ~Window();
    static Window *create();

    Window *setScale(Vector scale);
    Window *setScale(int x, int y);
    Window *setColor(ColorPair color);
    Window *setColor(Color foreground, Color background);
    Window *useObject(IObject *object);

    void init();
    void render();

private:
    Window();
    std::vector<IObject *> objects;
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
    void renderWindows();
};

#endif
