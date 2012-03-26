/* 
 * File:   Player.hpp
 * Author: nick
 *
 * Created on March 25, 2012, 5:24 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../include/Player.hpp"

class Player : public Unit 
{
    
public:
    Player(float x, float y, float maxSpeed);
    void render();
    void stepLogic();
private:
    
    
};

#endif	/* PLAYER_HPP */

