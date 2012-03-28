#include "../include/main.hpp"

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector::Vector(Vector* vector)
{
    x = vector->x;
    y = vector->y;
}

Vector Vector::operator +(Vector vector2)
{
    return new Vector(x+vector2.x, y+vector2.y);
}

Vector Vector::operator -(Vector vector2)
{
    return new Vector(x - vector2.x, y - vector2.y);
}

Vector Vector::operator *(float scale)
{
    return new Vector(x * scale, y * scale);
}

Vector Vector::operator /(float scale)
{
    return new Vector(x / scale, y / scale);
}

float Vector::dot(Vector vector2)
{
    return (x*vector2.x + y*vector2.y);
}

float Vector::lengthSquared()
{
    return ((float) (pow(x, 2) + pow(y, 2)));
}

float Vector::length()
{
    return (float) sqrt(lengthSquared());
}

Vector Vector::normalized()
{
    return ((*this) / length());
}

float Vector::distanceSquared(Vector vector2)
{
    return (float)(pow(vector2.x - x, 2) + pow(vector2.y - y, 2));
}

float Vector::distance(Vector vector2)
{
    return (float) (sqrt(distanceSquared(vector2)));
}



