#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PROMPTS 1
#define DEBUG 0

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

int addEvent(Link *sPtr, int processID, int arrivalTime, int CPUTime);

void bringToBack(Link node, Link *sPtr);

NODE createNode(int processID, int arrivalTime, int CPUTime);

Link createLink(NODE thisNode);

Link getNextEvent(Link *sPtr);

void printNode(Link node);

int processorSimulation(Link *sProcPtr, int timeSlice, int systemTimeIHMs);

void calcMeanAndVariance(double newTime);