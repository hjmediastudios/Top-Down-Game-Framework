#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include "main.hpp"

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
    virtual void render();
    virtual void stepLogic();

protected:
    float x;
    float y;
    int id;
    bool solid;
    //TODO add gameController
};


#endif	/* GAMEOBJECT_HPP */

