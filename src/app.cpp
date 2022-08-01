#include "elements/title.hpp"
#include "scenes/main.hpp"

using Creact::Color;
using Creact::registerScene;
using Creact::resizeTerminal;
using Creact::runApp;
using Creact::Vector;

int main() {
    resizeTerminal(80, 25);
    registerScene("main", mainScene);
    return runApp("main");
}
