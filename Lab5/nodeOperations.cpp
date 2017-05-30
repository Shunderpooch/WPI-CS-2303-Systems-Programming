//Author Project Partner, CS2303, Lab 5
#include "nodeOperations.h"
#include "globals.h"
#include "Node.h"
#include <cstdio>
#include <iostream>

using namespace std;
//Initializes sPtr
nodeOperations::nodeOperations(){
	sPtr = NULL;
}
//Adds an event to the proper position in the LinkedList, and returns 1 if successful, 0 if failed.
bool nodeOperations::addEvent(Link thisEvent){
	Link previousPtr, currentPtr;
	//check to make sure we have room in memory
	if(thisEvent){
		//add the pieces of information to the pointer
		currentPtr = sPtr;
		//Brings us to the correct position in the list for this item.
		while (currentPtr!=NULL && thisEvent->getArrivalTime() > currentPtr->getArrivalTime()){
			previousPtr = currentPtr;
			currentPtr = currentPtr->getNext();
		}
		//Are we at the beginning?
		if(previousPtr == NULL){
			thisEvent->setNext(sPtr);
			sPtr = thisEvent;
			return true;
		}
		//Now we're adding it to somewhere in the list
		else{
			previousPtr->setNext(thisEvent);
			thisEvent->setNext(currentPtr);
			return true;
		}
	}
	//Not enough memory otherwise
	else{
		printf("Uhmmm, we don't have enough memory to insert Process %d.", thisEvent->getPacketID());
		return false;
	}
}

//Brings the node to the back of the linkedlist given the node and the starting process.
void nodeOperations::bringToBack(Link node){
	Link previousPtr, currentPtr;
	previousPtr = NULL;
	currentPtr = sPtr;
	//Brings us to the correct position in the list for this item.
	if (DEBUG){
		printf("The node %d is about to move into place\n", node->getPacketID());
	}
	while (currentPtr != NULL){
		previousPtr = currentPtr;
		currentPtr = currentPtr->getNext();
	}
	//Are we at the beginning?
	if(previousPtr == NULL){
		node->setNext(NULL);
		sPtr = node;
	}
	//Now we're adding it to the end in the list
	else{
		previousPtr->setNext(node);
		node->setNext(NULL);
	}
}

//Takes the first event in the list, removing it from the linkedlist entirely, and returns that event.
Link nodeOperations::getNextEvent(){
	Link tempPtr;
	tempPtr = sPtr;
	sPtr = (sPtr)->getNext();
	tempPtr->setNext(NULL);
	return tempPtr;
}
//Gets the length for the list
int nodeOperations::getLength(){
	Link tempPtr = sPtr;
	int counter = 0;
	while (tempPtr != NULL){
		 counter += 1;
		 tempPtr = tempPtr->getNext();
	}
	return counter;
}
//decrements the time on every item in the quene.
bool nodeOperations::decrementTime(){
	Link tempPtr = sPtr;
	while (tempPtr != NULL){
		 tempPtr->setPropogationTime((tempPtr->getPropogationTime()-1));
		 if (DEBUG){
		 	printf("%d has a propogation time of %d. The quene size is %d.\n", tempPtr->getPacketID(), tempPtr->getPropogationTime(), getLength());
		 }
		 tempPtr = tempPtr->getNext();
	}
	if(sPtr->getPropogationTime() == 0){
		return true;
	}
	return false;
}
