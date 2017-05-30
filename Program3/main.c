//Arthur Dooner, CS2303 Section C02, ajdooner@wpi.edu
//Program 3
#include "globals.h"

void FCFS(Link *sPtr, Link *sProcPtr);

void RoundRobin(Link *sPtr, Link *sProcPtr, int timeSlice);

//Operates on the first item in the Processor Quene, dynamically for FCFS and RR. Returns the time used by the CPU across operating on this process.
int processorSimulation(Link *sProcPtr, int timeSlice, int systemTimeIHMs){
	//Gets the event at the head of the processor simulation to work on.
	Link node=getNextEvent(sProcPtr);
	if (DEBUG){
		printf("The processor is currently working on:\n");
		printNode(node);
	}
	//If the timeslice is equal to or greater than the node at the front process' remaining CPU time, then we can remove it from the list and return the time needed to run.
	if (timeSlice >= (node->CPUTime)){
		int CPUTime = (node->CPUTime);
		double TotalTime = (((double)systemTimeIHMs + CPUTime - (node->arrivalTime))/10);
		printf("\nProcess %4d has completed in %3lf seconds. It started at %3lf and ended at %3lf. \n", node->processID, TotalTime, ((double)node->arrivalTime)/10, ((double)systemTimeIHMs + CPUTime)/10);
		calcMeanAndVariance(TotalTime);
		free(node);
		return CPUTime;
	}
	//Otherwise, we remove time from the CPU time on the node and bring the node to the back. 
	else{
		node->CPUTime -= timeSlice;
		if (DEBUG){
			printf("Process %4d has been worked at for %lf seconds. The processor is moving it to the back and starting the next.\n", node->processID, (((double)timeSlice)/10));
		}
		bringToBack(node, sProcPtr);
		return timeSlice;
	}
}

//Dynamically gathers all of the needed times for each event and upon given the sentinel, calculates and prints out the mean and variance.
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
    //Start of the EventList
    Link sPtr = NULL;
    //Start of the Processor Quene
    Link sProcPtr = NULL;
    //This will be our sentinel throughout the program
    Link endPtr = createLink(createNode(-1, 0, 0));
    //Checks to make sure we have a valid form of input from the user. 
 	if(argv[1] == NULL || argv[2] == NULL || atoi(argv[1]) < 1){
 		printf("This format is incorrect. Relaunch the program in the form: ./<executable> <source-lines> <time-slice>\n");
 		return 0;
 	}
    numberOfProcesses = atoi(argv[1]);
    processTimes=malloc(sizeof(double)*numberOfProcesses);
    int milliSecondSliceforCPU = atoi(argv[2]);
    int processID, arrivalTime, CPUTime;
    //Builds the EventList from the user
	for(int x = 0; x < numberOfProcesses; x++){
		if (PROMPTS){
			printf("Please provide the process %d in the form: processID, arrivalTime, CPUTime\n", (x+1));
		}
		scanf("%d %d %d", &processID, &arrivalTime, &CPUTime);
		addEvent(&sPtr, processID, arrivalTime, CPUTime);
	}
	//Puts the sentinel at the end
	bringToBack(endPtr, &sPtr);
	//Checks to see if we should run FCFS
	if (milliSecondSliceforCPU == 0){
		FCFS(&sPtr, &sProcPtr);
		return 1;
	}
	//Checks to see if preemptive RR needs to run.
	//else if(atoi(argv[3])==1){
	//	preemptiveRR
	//}
	//The only remaining option is Round Robin.
	else{
		RoundRobin(&sPtr, &sProcPtr, milliSecondSliceforCPU);
	}
}
