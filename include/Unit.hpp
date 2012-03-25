/* 
 * File:   Unit.hpp
 * Author: nick
 *
 * Created on March 25, 2012, 10:09 AM
 */

#ifndef UNIT_HPP
#define	UNIT_HPP

#include "main.hpp"

class Unit : public GameObject {
public:
    Unit(float x, float y, float maxSpeed, int team);
    void render();
    void stepLogic();

private:
    float direction;
    float maxSpeed;
    float speed;
    float friction;
    int team;
    ALLEGRO_COLOR color;
};


#endif	/* UNIT_HPP */

