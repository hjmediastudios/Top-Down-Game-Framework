#include "include/main.hpp"

GameHandler::GameHandler()
{
    numObjects = 0;
    highestObjectID = 0;
    listing_head = NULL;
}

void GameHandler::registerObject(GameObject *object)
{
    ObjectListing *tempListing = new ObjectListing;
    
    tempListing->object = object;
    tempListing->next = listing_head;
    
    listing_head = tempListing;
    
    object->setID(highestObjectID);
    numObjects++;
    highestObjectID++;
}



void GameHandler::render_all()
{
    ObjectListing *iterator;
    for (iterator = listing_head; iterator != NULL; iterator = iterator->next)
        iterator->object->render();
}

