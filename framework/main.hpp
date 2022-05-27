#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/window.hpp"
#include "./core/vector.hpp"

#include <string>
#include <memory>

using string = std::string;

namespace std
{
    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args &&...args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

Object label(string text, Optional<ColorPair> color = nullptr);
Object label(string text, Vector position, Optional<ColorPair> color = nullptr);

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

#endif
