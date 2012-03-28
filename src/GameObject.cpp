#include "../include/main.hpp"
using namespace std;

GameObject::GameObject()
{
    GameObject(0.0, 0.0);
}

GameObject::GameObject(float x, float y)
{
    setPosition(x, y);
    id = 0;
}

GameObject::~GameObject()
{
    std::cout << "Deleted object #" <<  id << endl;
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

void GameObject::setListing(ObjectListing* listing)
{
    this->listing = listing;
}

ObjectListing* GameObject::getListing()
{
    return this->listing;
}

void GameObject::moveDirection(float angle, float speed)
{
    shiftPosition(speed*0.01*cos(deg2rad(angle)), speed*-0.01*sin(deg2rad(angle))); 
}

bool GameObject::isInBounds(float x1, float y1, float x2, float y2)
{
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}