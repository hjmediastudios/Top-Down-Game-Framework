#ifndef INPUT_HPP
#define	INPUT_HPP

#include "main.hpp"

class Input
{
public:
    Input();
    void poll();
    float get_lr();
    float get_ud();
    float get_ad();
    bool get_space();
    bool get_esc();
    
private:
    ALLEGRO_KEYBOARD_STATE keyboardState;
};


#endif	/* INPUT_HPP */