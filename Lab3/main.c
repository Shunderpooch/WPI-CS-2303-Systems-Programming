//Arthur Dooner, CS2303 Section C02, ajdooner@wpi.edu
//Lab 3
#include <stdio.h>
#include <stdlib.h>

//Creates the NODE struct
typedef struct NODE{
	int processID;
	int arrivalTime;
	int CPUTime;
	struct NODE *nextInList;
}NODE;
//Creates a pointer type for a link to the next node.
typedef NODE *Link;

//Creates a node based off of the provided information
NODE create_node(int processID, int arrivalTime, int CPUTime){
	NODE *nextInList = NULL;
	NODE thisNode={processID, arrivalTime, CPUTime, nextInList};
	return thisNode;
}
//Prints a node's information from a given node.
void print_node(NODE node){
	printf("This node has processID %d with an arrivalTime %d and a CPU Time of %d \n", node.processID, node.arrivalTime, node.CPUTime);
}

//Adds an event to the proper position in the LinkedList, and returns 1 if successful, 0 if failed.
int add_event(Link *sptr, NODE node){
	Link newPtr, previousPtr, currentPtr;
	newPtr = malloc(sizeof(NODE));
	//check to make sure we have room in memory
	if(newPtr){
		//add the pieces of information to the pointer
		newPtr->processID=node.processID;
		newPtr->arrivalTime=node.arrivalTime;
		newPtr->CPUTime=node.CPUTime;
		newPtr->nextInList=NULL;
		previousPtr=NULL;
		currentPtr=*sptr;
		//Brings us to the correct position in the list for this item.
		while (currentPtr!=NULL && node.arrivalTime > currentPtr->arrivalTime){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextInList;
		}
		//Are we at the beginning?
		if(previousPtr==NULL){
			newPtr->nextInList=*sptr;
			*sptr=newPtr;
			return 1;
		}
		//Now we're adding it to somewhere in the list
		else{
			previousPtr->nextInList=newPtr;
			newPtr->nextInList=currentPtr;
			return 1;
		}
	}
	//Not enough memory otherwise
	else{
		printf("Uhmmm, we don't have enough memory to insert Process %d.", node.processID);
		return 0;
	}
}

//Takes the first event in the list, removing it from the linkedlist entirely, and returnst that event.
NODE get_nextevent(Link *sptr){
	Link tempPtr;
	tempPtr=*sptr;
	*sptr=(*sptr)->nextInList;
	return create_node(tempPtr->processID, tempPtr->arrivalTime,tempPtr->CPUTime);
}

//Prints all of the events in the list.
void print_eventlist(Link thisPointer){
	if (thisPointer==NULL){
		printf("List is empty\n\n");
	}
	else{
		printf("The events follow as \n");
		while(thisPointer!=NULL){
			printf("Process ID: %d, arrivalTime: %d, and CPUTime: %d.\n", thisPointer->processID, thisPointer->arrivalTime, thisPointer->CPUTime);
			thisPointer=thisPointer->nextInList;
		}
		printf("End of List\n");
	}
}
//Takes in a certain amount of lines of command line input, adds them all as nodes to the list, and removes the first two from the list
//prints them, and finally prints the rest of the list. 
int main(int argc, char *argv[]){
    Link sptr;
    int numberOfLinesToRead=atoi(argv[1]);
    int processID, arrivalTime, CPUTime;
	for(int x=0; x<numberOfLinesToRead; x++){
		printf("Please provide the process %d in the form: processID, arrivalTime, CPUTime\n", (x+1));
		scanf("%d %d %d", &processID, &arrivalTime, &CPUTime);
		add_event(&sptr, create_node(processID, arrivalTime, CPUTime));
	}
	print_node(get_nextevent(&sptr));
	print_node(get_nextevent(&sptr));
	print_eventlist(sptr);
}
