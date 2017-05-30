#include "globals.h"

//Adds an event to the proper position in the LinkedList, and returns 1 if successful, 0 if failed.
int addEvent(Link *sPtr, int processID, int arrivalTime, int CPUTime){
	Link newPtr, previousPtr, currentPtr;
	newPtr = malloc(sizeof(NODE));
	//check to make sure we have room in memory
	if(newPtr){
		//add the pieces of information to the pointer
		newPtr->processID = processID;
		newPtr->arrivalTime = arrivalTime;
		newPtr->CPUTime = CPUTime;
		newPtr->nextInList = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		//Brings us to the correct position in the list for this item.
		while (currentPtr!=NULL && arrivalTime > currentPtr->arrivalTime){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextInList;
		}
		//Are we at the beginning?
		if(previousPtr == NULL){
			newPtr->nextInList = *sPtr;
			*sPtr = newPtr;
			return 1;
		}
		//Now we're adding it to somewhere in the list
		else{
			previousPtr->nextInList = newPtr;
			newPtr->nextInList = currentPtr;
			return 1;
		}
	}
	//Not enough memory otherwise
	else{
		printf("Uhmmm, we don't have enough memory to insert Process %d.", processID);
		return 0;
	}
}

//Brings the node to the back of the linkedlist given the node and the starting process.
void bringToBack(Link node, Link *sPtr){
	Link previousPtr, currentPtr;
	previousPtr = NULL;
	currentPtr = *sPtr;
	//Brings us to the correct position in the list for this item.
	while (currentPtr!=NULL){
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextInList;
	}
	//Are we at the beginning?
	if(previousPtr == NULL){
		node->nextInList = NULL;
		*sPtr = node;
	}
	//Now we're adding it to the end in the list
	else{
		previousPtr->nextInList = node;
		node->nextInList = NULL;
	}
}

//Creates a node based off of the provided information
NODE createNode(int processID, int arrivalTime, int CPUTime){
	NODE *nextInList=NULL;
	NODE thisNode = {processID, arrivalTime, CPUTime, nextInList};
	if (DEBUG){
		printf("Node has been created.\n");
	}
	return thisNode;
}

//Creates a link from a node
Link createLink(NODE thisNode){
	Link tempPtr;
	tempPtr = malloc(sizeof(NODE));
		//Memory check
		if (tempPtr){
			tempPtr->processID = thisNode.processID;
			tempPtr->arrivalTime = thisNode.arrivalTime;
			tempPtr->CPUTime = thisNode.CPUTime;
			tempPtr->nextInList = thisNode.nextInList;
			return tempPtr;
		}
		//Memory check failed case
		else{
			printf("There isn't enough memory to proceed");
			return tempPtr;
		}
}

//Takes the first event in the list, removing it from the linkedlist entirely, and returns that event.
Link getNextEvent(Link *sPtr){
	Link tempPtr;
	tempPtr = *sPtr;
	*sPtr = (*sPtr)->nextInList;
	return tempPtr;
}

//Prints a node's information from a given node.
void printNode(Link node){
	printf("ProcessID %d with an arrivalTime %d and a CPU Time of %d. \n", node->processID, node->arrivalTime, node->CPUTime);
}