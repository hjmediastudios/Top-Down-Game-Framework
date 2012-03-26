#include "../include/main.hpp"
using namespace std;

Unit::Unit(float x, float y, float maxSpeed, int team) : GameObject(x, y)
{
    this->maxSpeed = maxSpeed;
    speed = 0.0;
    friction = FRICTION;
    this->team = team;
    direction = 0.0;
    rotate(45);
    color = al_color_hsv(255.0 / (team + 1.0), 255.0, 255.0);
    maneuverability = 0.9;
}

void Unit::render()
{
    //    std::cout << "Rendering object #" << this->id << "...\n";
    al_draw_filled_circle(x, y, 10.0, color);
    al_draw_line(x, y, x + (20 * cos(deg2rad(direction))), y - (20 * sin(deg2rad(direction))), color, 3);
}

void Unit::stepLogic()
{
    //TODO change
    moveDirection(direction, speed);
}

void Unit::rotate(float degrees)
{
    if (degrees > 0.0)
    {
        if (direction < (360.0) - degrees)
            direction += degrees;
        else
            direction = (degrees + direction) - 360;
    } else
    {
        if (direction > 0.0 + degrees)
            direction += degrees;
        else
            direction = (direction + degrees) + 360;
    }
}


