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

void GameHandler::deregisterObject(GameObject *object)
{
    ObjectListing* del = object->getListing();
    /* base case */
    if (listing_head == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (listing_head == del)
        listing_head = del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->previous = del->previous;

    /* Change prev only if node to be deleted is NOT the first node */
    if (del->previous != NULL)
        del->previous->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

