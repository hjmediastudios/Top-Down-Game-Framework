#include "../include/main.hpp"
using namespace std;

Unit::Unit(float x, float y, float maxSpeed, int team) : GameObject(x, y)
{
    this->maxSpeed = maxSpeed;
    friction = FRICTION;
    this->team = team;
    direction = direction;
}

void Unit::render()
{
    std::cout << "Rendering object #" << this->id << "...\n";
    al_draw_filled_circle(x, y, 10.0, al_color_html("ffffff"));
    al_draw_line(x, y, x + (20*cos(deg2rad(direction))), x + (20*cos(deg2rad(direction))), al_color_html("ffffff"), 3);
}

void Unit::stepLogic()
{
    std::cout << "Step-logic on object #" << this->id << "...\n";
}
