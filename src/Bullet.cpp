#include "../include/main.hpp"

Bullet::Bullet(float x, float y, float direction, float speed) : GameObject(x, y)
{
    this->direction = direction;
    this->speed = speed;
}

void Bullet::render()
{
    al_draw_filled_circle(x, y, 2, al_color_html("666666"));
}

void Bullet::stepLogic()
{
//    if (isInBounds(0.0, 0.0, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        moveDirection(direction, speed);
    }
}