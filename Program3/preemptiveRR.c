#include "globals.h"

//Runs the preemptive round Robyn simulation. :)
void preemptiveRoundRobin(Link *sPtr, Link *sProcPtr, int timeSlice){
	int systemTimeIHMs;
	Link endPtr=createLink(createNode(-1, 0, 0));
	Link currentPtr=*sPtr;
	bringToBack(endPtr, sProcPtr);
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
				for(int x=0; x<timeSlice, x++){
					if(){

					}
					systemTimeIHMs+=processorSimulation(sProcPtr, 1, systemTimeIHMs);
				}
			
				if(DEBUG){
                    printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
				}
			}
		}
		//We must have no processes running if it's completely empty, but the CPU should print out
		//It has nothing to do but will still continue to search for 
		else if((*sProcPtr)->nextInList == NULL){
			systemTimeIHMs++;
			printf("WHERE'S THE NACHOS??? (The Processor has nothing to work on)\n");
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
			systemTimeIHMs+=processorSimulation(sProcPtr, timeSlice, systemTimeIHMs, 1);
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
				Link tempPtr = *sProcPtr;
				*sProcPtr = (*sProcPtr)->nextInList;
				tempPtr->nextInList = NULL;
				bringToBack(tempPtr, sProcPtr);
				printf("The sentinel has been moved to the back.");
		}
		else{
			systemTimeIHMs += processorSimulation(sProcPtr, timeSlice, systemTimeIHMs, 1);
			if(DEBUG){
                printf("The System time is %d Hundreds of Milliseconds.\n\n", systemTimeIHMs);
			}			
		}

	}
	calcMeanAndVariance(-1);
}

int additionalCalculation(Link *sProcPtr, Link *sPtr, int timeSlice, int systemTimeIHMs){
	for(int x = 0; x<timeSlice, x++){
		if (systemTimeIHMs==)
	}
}