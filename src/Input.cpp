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
    if (&keyboardState != NULL)
    {
        if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT))
            return -1.0;
        else if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT))
            return 1.0;
        else
            return 0.0;
    }
    else
    {
        std::cerr << "Couldn't read keyboard.\n";
        return 0.0;
    }
}

float Input::get_ud()
{
    if (&keyboardState != NULL)
    {
        if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN))
            return -1.0;
        else if (al_key_down(&keyboardState, ALLEGRO_KEY_UP))
            return 1.0;
        else
            return 0.0;
    }
    else
    {
        std::cerr << "Couldn't read keyboard.\n";
        return 0.0;
    }
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
