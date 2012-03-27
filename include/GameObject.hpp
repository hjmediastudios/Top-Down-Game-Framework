#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include "main.hpp"

struct ObjectListing;

class GameObject {
public:
    GameObject();
    GameObject(float x, float y);
    void setPosition(float x, float y);
    void shiftPosition(float xShift, float yShift);
    float getX();
    float getY();
    int getID();
    void setID(int id);
    void setListing(ObjectListing *listing);
    ObjectListing* getListing();
    virtual void render();
    virtual void stepLogic();
    void moveDirection(float angle, float speed);
    bool isInBounds(float x1, float y1, float x2, float y2);

protected:
    float x;
    float y;
    int id;
    bool solid;
    ObjectListing *listing;
};


#endif	/* GAMEOBJECT_HPP */

