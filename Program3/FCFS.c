#include "globals.h"

//Run the first come, first serve quene.
void FCFS(Link *sPtr, Link *sProcPtr){
	int systemTimeIHMs=0;
	Link currentPtr=*sPtr;
	//Runs while the list is not empty
	while (currentPtr->processID!=-1){
		//Checks to see if the currentPtr in the EventList has a time less than the system time.
		if(currentPtr->arrivalTime <= systemTimeIHMs){
			while(currentPtr->arrivalTime <= systemTimeIHMs && currentPtr->processID!=-1){
				if(DEBUG){
					printf("The processor is about to take an input. The System time is %d.\n \n", systemTimeIHMs);
				}
				//We always know this is going to be the start of the quene, as FCFS gives the total time needed for the program
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
		//The processor has nothing to work on, as not all of the events have shown up yet.
		else{
			systemTimeIHMs++;
			printf("WHERE'S THE NACHOS??? (The processor has nothing to work on)\n");
		}

	}
	calcMeanAndVariance(-1);
}