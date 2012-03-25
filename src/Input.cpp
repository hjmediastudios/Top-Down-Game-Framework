#include "../include/main.hpp"

Input::Input()
{
    //Create memory
    memset(&keyboardState, 0, sizeof(ALLEGRO_KEYBOARD_STATE));
}

void Input::poll()
{
    al_get_keyboard_state(&keyboardState);
}

double Input::get_lr()
{
    double returnValue = 0.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT))
        returnValue -= 1.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT))
        returnValue += 1.0;
    
    return returnValue;
}

double Input::get_ud()
{
    double returnValue = 0.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN))
        returnValue -= 1.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_UP))
        returnValue += 1.0;
    
    return returnValue;
}

double Input::get_ad()
{
    double returnValue = 0.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_A))
        returnValue -= 1.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_D))
        returnValue += 1.0;
    
    return returnValue;
}

bool Input::get_esc()
{
    return al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE);
}

bool Input::get_space()
{
    return al_key_down(&keyboardState, ALLEGRO_KEY_SPACE);
}
