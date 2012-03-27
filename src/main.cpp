#include <GL/gl_mangle.h>

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
    handler.setInput(&input);

    Player* unit = new Player(25.0, 150.0, 2.0, &input);
    handler.registerObject(unit);

    Unit* unit2 = new Unit(290.0, 395.0, 5.0, 1);
    handler.registerObject(unit2);
    
    Bullet* bullet = new Bullet(42.0, 42.0, -45.0, 2.0);
    handler.registerObject(bullet);
    
    Unit* unit3 = new Unit(500.0, 112.0, 5.0, 5);
    handler.registerObject(unit3);

    al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (true)
    {
        al_clear_to_color(al_color_html("112211"));

        input.poll();

        handler.stepLogic_all();
        handler.render_all();

        al_flip_display();

        if (input.get_esc())
        {
            break;
        }
    }
    return 22;
}

