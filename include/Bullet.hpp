/* 
 * File:   Bullet.hpp
 * Author: nick
 *
 * Created on March 26, 2012, 5:38 PM
 */

#ifndef BULLET_HPP
#define	BULLET_HPP

#include "main.hpp"

class Bullet : public GameObject 
{
public:
    Bullet(float x, float y, float direction, float speed);
    ~Bullet();
    void render();
    void stepLogic();
private:
    float direction;
    float speed;
};


#endif	/* BULLET_HPP */

