#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include "main.hpp"

class GameHandler;

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
//    void setHandler(GameHandler *handler);
//    GameHandler* getHandler();
    virtual void render();
    virtual void stepLogic();
    void moveDirection(float angle, float speed);

protected:
    float x;
    float y;
    int id;
//    GameHandler *handler;
    bool solid;
    //TODO add gameController
};


#endif	/* GAMEOBJECT_HPP */

