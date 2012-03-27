#include "../include/main.hpp"

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
    tempListing->object->setListing(tempListing);
    tempListing->object->getListing()->handler = this;
    tempListing->previous = NULL;

    if (listing_head != NULL)
        listing_head->previous = tempListing;
    
    listing_head = tempListing;

    object->setID(highestObjectID);
    numObjects++;
    highestObjectID++;
}

void GameHandler::render_all()
{
    ObjectListing *iterator;
    for (iterator = listing_head; iterator != NULL; iterator = iterator->next)
    {
        if (iterator->object != NULL)
            iterator->object->render();
    }
    delete iterator;
}

void GameHandler::stepLogic_all()
{
    ObjectListing *iterator;
    for (iterator = listing_head; iterator != NULL; iterator = iterator->next)
    {
        if (iterator->object != NULL)
            iterator->object->stepLogic();
    }
    delete iterator;
}

void GameHandler::setInput(Input* input)
{
    this->input = input;
}

Input *GameHandler::getInput()
{
    return input;
}

void GameHandler::deregisterObject(GameObject *object, bool deleteObj)
{
    ObjectListing* tempListing = object->getListing();

    if (tempListing->next == NULL && tempListing->previous == NULL)
    {
        std::cout << "Only node!\n";
        listing_head = NULL;
    }
    else if (tempListing->previous == NULL) //first node
    {
        //Listing is the first listing
        if (tempListing->next != NULL)
            listing_head = tempListing->next;
        else
            listing_head = NULL;
    }
    else if (tempListing->next == NULL)
    {
        //Listing is the last listing
        if (tempListing->previous != NULL)
            tempListing->previous->next = NULL;
    }
    else
    {
        //Listing is in the middle
        tempListing->previous->next = tempListing->next;
        tempListing->next->previous = tempListing->previous;
    }

    if (deleteObj)
    {
        delete object;
    }

//    std::cout << "deleted object: " << tempListing->object->getID() << "\n";
}
