#include "../main.hpp"

App myApp() {
    return createApp()
        .useWindow(myWindow())
        .done();
}
