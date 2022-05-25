#include "../../framework/core/window.hpp"
#include <string>

class MainWindow : public Window
{
public:
    void init() override;
    void update() override;

private:
    Object *title = new Object();
    Object *subTitle = new Object();
};
