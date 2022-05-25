#ifndef __FRAMEWORK_CORE_LABEL__
#define __FRAMEWORK_CORE_LABEL__

#include "object.hpp"
#include "../utils/vector.hpp"
#include "../utils/optional.hpp"
#include "../utils/color.hpp"
#include <string>

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

#endif
