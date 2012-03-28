#include "../include/main.hpp"

Input::Input()
{
    //Create memory
    memset(&keyboardState, 0, sizeof (ALLEGRO_KEYBOARD_STATE));
}

void Input::poll()
{
    al_get_keyboard_state(&keyboardState);
}

float Input::get_lr()
{
    float rValue = 0.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT) && !al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT))
        rValue = -1.0;
    else if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT) && !al_key_down(&keyboardState, ALLEGRO_KEY_LEFT))
        rValue = 1.0;
    else
        rValue =  0.0;
    std::cout << "Input state: " << rValue << std::endl;
    return rValue;
}

float Input::get_ud()
{
    float uValue = 0.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN))
        uValue -= 1.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_UP))
        uValue += 1.0;

    return uValue;
}

float Input::get_ad()
{
    if (al_key_down(&keyboardState, ALLEGRO_KEY_A))
        return -1.0;
    if (al_key_down(&keyboardState, ALLEGRO_KEY_D))
        return 1.0;
}

bool Input::get_esc()
{
    return al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE);
}

bool Input::get_space()
{
    return al_key_down(&keyboardState, ALLEGRO_KEY_SPACE);
}
