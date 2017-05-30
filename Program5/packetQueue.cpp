//Author Arthur Dooner, CS2303, Lab 5
#include "packetQueue.h"
#include "globals.h"
#include "Packet.h"
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
//Initializes sPtr
packetQueue::packetQueue(){
	sPtr = NULL;
}
//Adds an event to the proper position in the LinkedList, and returns 1 if successful, 0 if failed.
bool packetQueue::addEvent(Link thisEvent){
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
void packetQueue::bringToBack(Link node){
	Link previousPtr, currentPtr;
	previousPtr = NULL;
	currentPtr = sPtr;
	//Brings us to the correct position in the list for this item.
	if (DEBUG){
		cout << "The packet "<< node->getPacketID() << " is about to move to the back. " << endl;
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
Link packetQueue::getNextEvent(){
	Link tempPtr;
	tempPtr = sPtr;
	sPtr = (sPtr)->getNext();
	tempPtr->setNext(NULL);
	return tempPtr;
}
//Returns the next event, provided a starting location.
Link packetQueue::getNextEvent(Link *aPtr){
	Link tempPtr;
	tempPtr = *aPtr;
	aPtr = (&(*aPtr)->next);
	tempPtr->setNext(NULL);
	return tempPtr;
}
//Gets the length for the list
int packetQueue::getLength(){
	Link tempPtr = sPtr;
	int counter = 0;
	while (tempPtr != NULL){
		 counter += 1;
		 tempPtr = tempPtr->getNext();
	}
	return counter;
}
//decrements the time on every item in the Queue.
vector<Link> packetQueue::decrementTime(){
	vector<Link> whatsBeenMade;
	Link previousPtr = NULL;
	Link currentPtr, tempPtr;
	currentPtr = sPtr;
	if (DEBUG){
	}
	if (sPtr == NULL){
		return whatsBeenMade;
	}
	while (currentPtr){
		if (currentPtr->getPropogationTime() <= 0){
			if (previousPtr == NULL){
				sPtr = currentPtr->next;
			}
			else{
				previousPtr->next = currentPtr->next;
			}
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			tempPtr->next = NULL;
			whatsBeenMade.push_back(tempPtr);
		}
		else{
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
	}
	if (sPtr != NULL){
		sPtr = sPtr->decrementItems();
	}
	return whatsBeenMade;
}

//Returns the size of the first packet in the list
int packetQueue::getFirstSize(){
	return sPtr->getPacketSize();
}
//Returns the Finish time of the first packet in the list.
int packetQueue::getFirstFinish(){
	return sPtr->getFinishTime();
}

