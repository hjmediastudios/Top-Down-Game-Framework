#ifndef INPUT_HPP
#define	INPUT_HPP

#include "main.hpp"

class Input
{
public:
    Input();
    void poll();
    double get_lr();
    double get_ud();
    double get_ad();
    bool get_space();
    bool get_esc();
    
private:
    ALLEGRO_KEYBOARD_STATE keyboardState;
};


#endif	/* INPUT_HPP */