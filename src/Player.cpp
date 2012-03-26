#include "../include/main.hpp"

Player::Player(float x, float y, float maxSpeed) : Unit(x, y, maxSpeed, 0)
{

}

void Player::render()
{
    Unit::render();
}
//TODO git me!
void Player::stepLogic()
{
    float accel = handler->getInput()->get_ud();

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
    

    rotate(handler->getInput()->get_lr()*-0.025);
    moveDirection(direction, speed);
    Unit::stepLogic();
}
