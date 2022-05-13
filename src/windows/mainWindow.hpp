#include "../../core/window.hpp"
#include <string>

class MainWindow : public Window
{
public:
    void update() override;

private:
    int tickCount = 0;
};
