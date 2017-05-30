//Arthur Dooner, CS2303 Section C02, ajdooner@wpi.edu
//Program 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define DEBUG 1

//Creates the NODE struct
typedef struct NODE{
	int processID;
	int arrivalTime;
	int CPUTime;
	struct NODE *nextInList;
}NODE;

//Creates a pointer type for a link to the next node.
typedef NODE *Link;

int numberOfProcesses;
double *processTimes;

//Creates a node based off of the provided information
NODE createNode(int processID, int arrivalTime, int CPUTime){
	NODE *nextInList;
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
//Prints a node's information from a given node.
void printNode(Link node){
	printf("This node has processID %d with an arrivalTime %d and a CPU Time of %d \n", node->processID, node->arrivalTime, node->CPUTime);
}

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


//Takes the first event in the list, removing it from the linkedlist entirely, and returns that event.
Link getNextEvent(Link *sPtr){
	Link tempPtr;
	tempPtr = *sPtr;
	*sPtr = (*sPtr)->nextInList;
	return tempPtr;
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

//Prints all of the events in the list.
void printEventList(Link thisPointer){
	//Check to see if the list is empty
	if (thisPointer == NULL){
		printf("List is empty\n\n");
	}
	//Print the events otherwise
	else{
		printf("The events follow as \n");
		//Loops through the linkedList for its entire length.
		while(thisPointer != NULL){
			printf("Process ID: %d, arrivalTime: %d, and CPUTime: %d.\n", thisPointer->processID, thisPointer->arrivalTime, thisPointer->CPUTime);
			thisPointer = thisPointer->nextInList;
		}
		printf("End of List\n");
	}
}
int processorSimulation(Link *sProcPtr, int timeSlice, int systemTimeIHMs);
void calcMeanAndVariance(double newTime);

//Run the first come, first serve Queue.
void FCFS(Link *sPtr, Link *sProcPtr){
	int systemTimeIHMs=0;
	Link endPtr=createLink(createNode(-1, 0, 0));
	Link currentPtr=*sPtr;
	//Runs while the list is not empty
	while (currentPtr->processID!=-1){
		if(currentPtr->arrivalTime <= systemTimeIHMs){
			while(currentPtr->arrivalTime <= systemTimeIHMs && currentPtr->processID!=-1){
				if(DEBUG){
					printf("The processor is about to take an input. The System time is %d.\n \n", systemTimeIHMs);
				}
				//We always know this is going to be the start of the Queue, as FCFS gives the total time needed for the program
				Link tempPtr=currentPtr;
				currentPtr=(currentPtr)->nextInList;
				tempPtr->nextInList=NULL;
				bringToBack(tempPtr, sProcPtr);
				systemTimeIHMs+=processorSimulation(sProcPtr, tempPtr->CPUTime, systemTimeIHMs);
				if(DEBUG){
                    printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
				}
			}
		}
		else{
			systemTimeIHMs++;
			printf("WHERE'S THE NACHOS??? (The processor has nothing to work on)\n");
		}

	}
	calcMeanAndVariance(-1);
}

//Runs the round Robyn simulation. :)
void RoundRobin(Link *sPtr, Link *sProcPtr, int timeSlice){
	int systemTimeIHMs;
	Link endPtr=createLink(createNode(-1, 0, 0));
	Link currentPtr=*sPtr;
	bringToBack(endPtr, sProcPtr);
	Link startProcPtr=*sProcPtr;
	//Runs while the Queue list is not empty
	while (currentPtr->processID!=-1){
		if(currentPtr->arrivalTime <= systemTimeIHMs){
			//check to see if we are backordered with processes, whereupon we have to put them in the Queue
			while(currentPtr->arrivalTime <= systemTimeIHMs && currentPtr->processID!=-1){
				if(DEBUG){
					printf("The processor is about to take an input. The System time is %d.\n \n", systemTimeIHMs);
				}
				//Again, if these are first being added, then it won't matter because they're all sharing a timeslice
				Link tempPtr=currentPtr;
				currentPtr=(currentPtr)->nextInList;
				tempPtr->nextInList=NULL;
				bringToBack(tempPtr, sProcPtr);
				if((*sProcPtr)->processID==-1){
					Link tempPtr2=*sProcPtr;
					*sProcPtr=(*sProcPtr)->nextInList;
					tempPtr2->nextInList=NULL;
					bringToBack(tempPtr2, sProcPtr);
				}
				systemTimeIHMs+=processorSimulation(sProcPtr, timeSlice, systemTimeIHMs);
				if(DEBUG){
                    printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
				}
			}
		}
		//We must have no processes running if it's completely empty, but the CPU should print out
		//It has nothing to do but will still continue to search for 
		else if((*sProcPtr)->nextInList == NULL){
			systemTimeIHMs++;
			printf("WHERE'S THE NACHOS???\n");

		}
		//We looped to the endPtr without it actually being at the end, and still have processes to run.
		else if((*sProcPtr)->processID == -1){
				Link tempPtr=*sProcPtr;
				*sProcPtr=(*sProcPtr)->nextInList;
				tempPtr->nextInList=NULL;
				bringToBack(tempPtr, sProcPtr);
		}
		//Since we certainly aren't at the end or out of processes, we can run the program normally.
		else{
			systemTimeIHMs+=processorSimulation(sProcPtr, timeSlice, systemTimeIHMs);
			if(DEBUG){
                    printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
			}
		}
	}
	if (DEBUG){
		printf("\n\n\nWE HAVE MADE IT TO THE SECOND WHILE\n\n\n");
	}
	//Round Robin will undoubtably continue functioning even after all the processes have arrived.
	while ((*sProcPtr)->nextInList != NULL){
		if((*sProcPtr)->processID == -1){
				Link tempPtr=*sProcPtr;
				*sProcPtr=(*sProcPtr)->nextInList;
				tempPtr->nextInList=NULL;
				bringToBack(tempPtr, sProcPtr);
				printf("The sentinel has been moved to the back.");
		}
		else{
			systemTimeIHMs+=processorSimulation(sProcPtr, timeSlice, systemTimeIHMs);
			if(DEBUG){
                printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
			}			
		}

	}
	calcMeanAndVariance(-1);
}

int processorSimulation(Link *sProcPtr, int timeSlice, int systemTimeIHMs){
	Link node=getNextEvent(sProcPtr);
	if (DEBUG){
		printf("The processor is currently working on:\n");
		printNode(node);
	}
	if (timeSlice >= (node->CPUTime)){
		int CPUTime = (node->CPUTime);
		double TotalTime = (((double)systemTimeIHMs + CPUTime - (node->arrivalTime))/10);
		printf("\nProcess %d has completed in %lf seconds.\n", node->processID, TotalTime);
		calcMeanAndVariance(TotalTime);
		free(node);
		return CPUTime;
	}
	else{
		node->CPUTime -= timeSlice;
		printf("Process %d has been worked at for %lf seconds. The processor is moving it to the back and starting the next.\n", node->processID, (((double)timeSlice)/10));
		bringToBack(node, sProcPtr);
		return timeSlice;
	}
}

void calcMeanAndVariance(double newTime){
	static int counter = 0;
	double sum = 0;
	double varianceSum, variance, mean;

	if (newTime == -1){
		for (int i = 0; i < numberOfProcesses; i++){
			sum += processTimes[i];
		}
		mean = sum / numberOfProcesses;
		for (int j = 0; j < numberOfProcesses; j++){
			varianceSum+= pow((processTimes[j]-mean), 2);
		}
		variance=varianceSum/(numberOfProcesses-1);
		printf("Mean of this data: %lf Variance: %lf\n", mean, variance);
	}
	else{
		processTimes[counter]=newTime;
		counter++;
		if (DEBUG){
			printf("The time %lf seconds was added to the list at position %d\n", newTime, counter);
		}
	}

}
//Takes in a certain amount of lines of command line input, adds them all as nodes to the list, and removes the first two from the list
//prints them, and finally prints the rest of the list.
int main(int argc, char *argv[]){
	printf("Initial print\n");
    Link sPtr = NULL;
    Link sProcPtr = NULL;
    Link endPtr = createLink(createNode(-1, 0, 0));
 	if(argv[1] == NULL || argv[2] == NULL){
 		printf("This format is incorrect. Relaunch the program in the form: ./<executable> <source-lines> <time-slice>\n");
 		return 0;
 	}
    numberOfProcesses = atoi(argv[1]);
    processTimes=malloc(sizeof(double)*numberOfProcesses);
    int milliSecondSliceforCPU = atoi(argv[2]);
    int processID, arrivalTime, CPUTime;
	for(int x = 0; x < numberOfProcesses; x++){
		printf("Please provide the process %d in the form: processID, arrivalTime, CPUTime\n", (x+1));
		scanf("%d %d %d", &processID, &arrivalTime, &CPUTime);
		addEvent(&sPtr, processID, arrivalTime, CPUTime);
	}
	bringToBack(endPtr, &sPtr);
	if (milliSecondSliceforCPU == 0){
		FCFS(&sPtr, &sProcPtr);
		return 1;
	}
	else{
		RoundRobin(&sPtr, &sProcPtr, milliSecondSliceforCPU);
	}
}
