#include "../include/main.hpp"

Transform::Transform(float posX, float posY, float rot, float scl) : position(posX, posY), scale(scl), rotation(rot)
{

}

Transform::Transform(Vector pos, float rot, float scl) : position(pos), rotation(rot), scale(scl)
{

}

void Transform::translate(Vector vector2)
{
    position = position + vector2;
}

void Transform::translate(float x, float y)
{
    position.x += x;
    position.y += y;
}

void Transform::rotate(float theta)
{
    rotation += theta;
    if (rotation >= 360)
        rotation -= 360;
    if (rotation < 0)
        rotation += 360;
}