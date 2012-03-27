#include "../include/main.hpp"

Player::Player(float x, float y, float maxSpeed, Input* controls) : Unit(x, y, maxSpeed, 0)
{
    shotTimer = 30;
    this->controls = controls;
}

void Player::render()
{
    Unit::render();
}
//TODO git me!
void Player::stepLogic()
{
    //Movement code
    float accel = controls->get_ud();

    speed = accel + (speed*(-1*(accel < 0.0)));

    if (fabs(speed) >= maxSpeed)
    {
        if (speed < 0.0)
            speed = -1.0 * maxSpeed;
        else
            speed = maxSpeed;
    }
    
    if (speed < 0.0)
        speed += (friction*speed*-1);
    else
        speed -= (friction*speed);
    
    //Firing code
    if (listing->handler->getInput()->get_space() && shotTimer == 0)
    {
        Bullet *bullet = new Bullet(x, y, direction, 10.0);
        listing->handler->registerObject(bullet);
        shotTimer = 200;
    }
    
    //Count down shot timer
    if (shotTimer > 0)
        shotTimer--;
    
    rotate(listing->handler->getInput()->get_lr()*-0.025);
    moveDirection(direction, speed);
    Unit::stepLogic();
}
