#ifndef __FRAMEWORK_CORE_BORDER__
#define __FRAMEWORK_CORE_BORDER__

#include "object.hpp"
#include "../utils/optional.hpp"
#include "../utils/color.hpp"

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

#endif