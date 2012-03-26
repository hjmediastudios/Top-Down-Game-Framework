/* 
 * File:   GameHandler.hpp
 * Author: nick
 *
 * Created on March 25, 2012, 10:36 AM
 */

#ifndef GAMEHANDLER_HPP
#define	GAMEHANDLER_HPP

#include "main.hpp"

struct ObjectListing
{
    GameObject *object;
    ObjectListing *next;
};

class GameHandler
{
public:
    GameHandler();
    void registerObject(GameObject *object);
    void registerHeadObject(GameObject *object);
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

