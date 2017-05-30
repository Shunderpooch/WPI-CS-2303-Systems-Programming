//Attempted by Project Partner
//Code did not work
//Rewritten by Arthur Dooner, CS2303 Program 5
#include "Graph.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include "globals.h"
#include "FCFS.h"

Graph::Graph(int squarelen, int sender, int mule, int receiver){
	vector<int> tempVector;
	//Build an empty grid filler
	for (int y = 0; y < (squarelen + 2); y++){
		tempVector.push_back(-1);
	}
	if(DEBUG){
		cout << "Created the temporary vector" << endl;
	}
	//Fill the single dimension vector with another single dimension vector.
	for (int x = 0; x < squarelen; x++){
		manetmap.push_back(tempVector);
	}
	if(DEBUG){
		cout << "Created the empty grid." << endl;
	}
	dimension = squarelen;
	senderCount = sender;
	muleCount = mule;
	receiverCount = receiver;
	items = new vector<FCFS*>;
	items->resize(senderCount + muleCount + receiverCount);
	if(DEBUG){
		cout << "Resized the vector of all items." << endl;
	}
}
//Takes in a pointer to a sender and places it on the grid, sets its location, and adds it to the list of all the elements.
void Graph::addToGrid(Sender* thisSender){
	srand(time(NULL));
	int rand1;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		if (manetmap[rand1][0] == -1){
			noSpot = false;
			thisSender->setLoc(rand1, 0);
			manetmap[rand1][0] = thisSender->getID();
			(*items)[(thisSender->getID() - 1)] = (FCFS*)thisSender;
		} 
	}
}
//Takes in a pointer to a mule and places it on the grid, sets its location, and adds it to the list of all the elements.
void Graph::addToGrid(Mule* thisMule){
	srand(time(NULL));
	int rand1, rand2;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		rand2 = rand() % dimension;
		if (manetmap[rand1][(rand2 + 1)] == -1){
			noSpot = false;
			manetmap[rand1][rand2 + 1] = thisMule->getID();
			thisMule->setLoc(rand1, (rand2 + 1));
			(*items)[(thisMule->getID() - 1)] = (FCFS*)thisMule;  
		} 
	}
}
//Takes in a pointer to a receiver and places it on the grid, sets its location, and adds it to the list of all the elements.
void Graph::addToGrid(Receiver* thisReceiver){
	srand(time(NULL));
	int rand1;
	bool noSpot = true;
	while (noSpot){
		rand1 = rand() % dimension;
		if (manetmap[rand1][(dimension + 1)] == -1){
			noSpot = false;
			manetmap[rand1][(dimension + 1)] = thisReceiver->getID();
			thisReceiver->setLoc(rand1, (dimension + 1));
			(*items)[(thisReceiver->getID() - 1)] = (FCFS*)thisReceiver;
		} 
	}
}
//Prints the Grid
void Graph::printGrid(int simTime){
	cout << "The board at time " << simTime << " sims follows as: " << endl;
	for(int x = 0; x < (dimension + 2); x++){
		printf("%3d", x);
	}
	printf("\n+");
	for (int y = 0;  y < (dimension + 2); y++){
		printf("--+");
	}
	printf("\n");
	for(int i = 0; i < dimension; i++){
		for (int j = 0; j < (dimension + 2); j++){
			if (manetmap[i][j] == -1){
				printf("|  ");
			}
			else {
				printf("|%2d", manetmap[i][j]);
			}
		}
		printf("|%d\n+", i);
		for (int z = 0; z < (dimension + 2); z++){
			printf("--+");
		}
		printf("\n");
	}
}
//Moves an individual mule on the board.
void Graph::moveMule(Mule **thisMule){
	int dY = 0;
	int dX = 0;
	switch((*thisMule)->getDirection()){
		case NORTH:
			if((*thisMule)->getLocY() == 0){
				(*thisMule)->invertDirection();
			}
			else{
				dY = -1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case SOUTH:
			if((*thisMule)->getLocY() == (dimension - 1)){
				(*thisMule)->invertDirection();
			}
			else{
				dY = 1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case EAST:
			if((*thisMule)->getLocX() == dimension) {
				(*thisMule)->invertDirection();
			}
			else{
				dX = 1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case WEST:
			if((*thisMule)->getLocX() == 1){
				(*thisMule)->invertDirection();
			}
			else{
				dX = -1;
				makeMove(thisMule, dY, dX);
			}
			break;
		case EMPTY:
			break;
		default:
			printf("There was some sort of error with moving %d.\n", (*thisMule)->getID());
			break;
	}
}
//Moves the Mule after the direction has been changed.
void Graph::makeMove(Mule **thisMule, int dY, int dX){
	//First, let us check to see if we can clear the space we were at before.
	int curLocY = (*thisMule)->getLocY();
	int curLocX = (*thisMule)->getLocX();
	if((*thisMule)->getID() == manetmap[curLocY][curLocX]){
		manetmap[curLocY][curLocX] = -1;
	}
	//Now, check: is it an empty space?
	if (manetmap[(curLocY + dY)][(curLocX + dX)] == -1){
		manetmap[(curLocY + dY)][(curLocX + dX)] = (*thisMule)->getID();
		(*thisMule)->setLoc((curLocY + dY),(curLocX + dX));
        if (DEBUG){
			printf("Mule %d moved to %dY, %dX.\n", (*thisMule)->getID(), (curLocY + dY), (curLocX + dX));
		}
		return;
	}
	//Since the spot isn't empty, it has to be another mule. We'll jump onto it and move again. 
	else{
		(*thisMule)->setLoc((curLocY + dY), (curLocX + dX));
		moveMule(thisMule);
	}
}
//Move several Mules throughout the simulation.
void Graph::moveManyMules(){
	for(int x = 0; x < muleCount; x++){
		moveMule((Mule**)&((*items)[(x + senderCount)]));
	}
}
//Runs a round of the simulation
bool Graph::runARound(int simTime){
	bool simulationStillInProgress = false;
	for(unsigned int y = 0; y < items->size(); y++){
		FCFS *thisFCFS = ((*items)[y]);
		bool tempBool = false;
		//Run any sender activity
		if(y < (unsigned int)(senderCount) && thisFCFS->getArrivalTime() <= simTime){
			if (y == 0) {
				cout << endl << "The Sender activities follow here:" << endl;
			}
			tempBool = ((Sender*)thisFCFS)->runner(&items, simTime);
			(*items)[y] = thisFCFS;
		}
		//Run any mule activity
		else if (y < (unsigned int)(senderCount + muleCount) && thisFCFS->getArrivalTime() <= simTime){
			if (y == (unsigned int)senderCount){
				cout << endl << "The Mule activities follow here:" << endl;
			}
			tempBool = ((Mule*)thisFCFS)->runner(&items, simTime);
			(*items)[y] = thisFCFS;
		}
		if (tempBool == true){
			simulationStillInProgress = true;
		}
	}
	//Make moves if the time is right
	if ((simTime % 10 == 0) && (simTime != 0)){
		moveManyMules();
	}
	//Print board if the time is right
	if((simTime % 100 == 0) && (simTime != 0)){
		printGrid(simTime);
	}
	return simulationStillInProgress;
}
//Runs the simulation starting at time 0
void Graph::runSimulation(){
	int simTime = 0;
	bool simulationStillInProgress = true;
	printGrid(simTime);
	while (simulationStillInProgress){
		cout << endl << "Simulation Time: " << simTime << " sims" << endl; 
		simulationStillInProgress = runARound(simTime);
		simTime++;
	}
	printGrid(simTime);
	//Build and print out all the vectors and calculations to be done.
	for(unsigned int x = (senderCount + muleCount); x < items->size(); x++){
		((Receiver*)((*items)[x]))->buildVectors(senderCount);
		((Receiver*)((*items)[x]))->printCalculations();
	}
}

