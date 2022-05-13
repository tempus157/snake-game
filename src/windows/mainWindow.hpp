#include "../../framework/core/window.hpp"
#include <string>

class MainWindow : public Window
{
public:
    void init() override;
    void update() override;

private:
    Object *title = new Object("화면에 ■ □ ✅⬛⬛⬜💘 💓인쇄");
    int tickCount = 0;
};
