#include "../include/main.hpp"
using namespace std;

void init()
{
    al_init();
    al_init_primitives_addon();
    
    al_install_keyboard();
}

int main(int argc, char** argv)
{
    init();
    
    Input input = Input();
    
    GameHandler handler = GameHandler();
    
    Unit unit = Unit(25.0, 150.0, 2.0, 0);
    handler.registerObject(&unit);
    
    Unit unit2 = Unit(290.0, 395.0, 5.0, 1);
    handler.registerObject(&unit2);
    
    Unit unit3 = Unit(500.0, 112.0, 5.0, 5);
    handler.registerObject(&unit3);
    
    al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (true) {
        al_clear_to_color(al_color_html("112211"));
        input.poll();
        
        handler.stepLogic_all();
        handler.render_all();
        
        al_flip_display();
        
        if (input.get_esc())
            break;
    }
    return 0;
}

