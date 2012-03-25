#include "../include/main.hpp"

GameObject::GameObject()
{
    GameObject(0.0, 0.0);
}

GameObject::GameObject(float x, float y)
{
    setPosition(x, y);
    id = 0;
}

float GameObject::getX()
{
    return x;
}

float GameObject::getY()
{
    return y;
}

void GameObject::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void GameObject::shiftPosition(float xShift, float yShift)
{
    x += xShift;
    y += yShift;
}
//
void GameObject::render()
{
    //A rendering method for once-per-cycle implementation by child objects.
}

void GameObject::stepLogic()
{
    //A virtual method for once-per-cycle logic implemented by child objects.
}

int GameObject::getID()
{
    return this->id;
}

void GameObject::setID(int id)
{
    this->id = id;
}
