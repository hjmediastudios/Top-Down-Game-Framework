/* 
 * File:   GameHandler.hpp
 * Author: nick
 *
 * Created on March 25, 2012, 10:36 AM
 */

#ifndef GAMEHANDLER_HPP
#define	GAMEHANDLER_HPP

#include "main.hpp"

class GameHandler;

struct ObjectListing
{
    GameObject *object;
    GameHandler *handler;
    
    ObjectListing *previous;
    ObjectListing *next;
};

class GameHandler
{
public:
    GameHandler();
    void registerObject(GameObject *object);
    void deregisterObject(GameObject *object);
    void render_all();
    void stepLogic_all();
    void setInput(Input *input);
    Input *getInput();
private:
    Input *input;
    ObjectListing *listing_head;
    int numObjects;
    int highestObjectID;
};

#endif	/* GAMEHANDLER_HPP */

