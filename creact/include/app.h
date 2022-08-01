#ifndef __CREACT_APP__
#define __CREACT_APP__

#include <functional>
#include <map>
#include <string>

#include "color.h"
#include "element.h"
#include "vector.h"

namespace InternalCreact {
    Creact::Vector size;
    std::map<const std::string, std::function<Creact::Element()>> scenes;
    std::string activeSceneName;

    bool shouldProgress = true;
    bool shouldUpdate = true;

    void mountApp();
    void updateApp();
    void receiveInput();
}

namespace Creact {
    void resizeTerminal(const int x, const int y);
    void registerScene(const std::string &name,
        const std::function<Element()> scene);
    int runApp(const std::string &sceneName);

    void changeScene(const std::string &name);
    void quitApp();
}

#endif
