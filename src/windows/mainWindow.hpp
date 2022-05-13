#include "../../core/window.hpp"
#include <string>

class MainWindow : public Window
{
public:
    void init() override;
    void update() override;
    void release() override;

private:
    int tickCount;
};
