#include "./src/main.hpp"

int main() {
    const auto app = myApp();
    app.mount();
    app.update();
    app.receiveInput();
    app.destroy();
    return 0;
}