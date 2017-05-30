//Attempted by Project Partner
//Code partially worked
//Took functioning parts of her code, rewrote as Author Arthur Dooner, CS2303, Program 5
#include "FCFS.h"
#include "packetQueue.h"
#include "Packet.h"
#include "globals.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>

using namespace std;

//Global Function that adds sources from a file to the graph.
int addFromFile(string fileName, int sources, Graph** theGraph){
	static long positionAlongFile;
	int sID, arrivalTime, packets, packetSize, SRsize;
	int numberOfPackets = 0;
	vector<int> SR;
	vector<int> emptyVector;
	FILE *thisFile;
	thisFile = fopen((fileName + ".txt").c_str(), "r");
	if(thisFile != NULL){
		for (int y = 0; y < sources; y++) {
			fseek(thisFile, positionAlongFile, SEEK_SET);
			//Scanning in the input file
			fscanf(thisFile, "%d %d %d %d %d", &sID, &arrivalTime, &packets, &packetSize, &SRsize);
			for (int x = 0; x < SRsize; x++){
				int SRPart;
				fscanf(thisFile, "%d", &SRPart);
				SR.push_back(SRPart);
			}
			positionAlongFile = ftell(thisFile);
			if (DEBUG){
				printf("Adding Source %d from file.\n", sID);
			}
			//This builds the Source from the given data
			Sender *thisSender = new Sender(sID, arrivalTime, packets, packetSize, SR);
			SR = emptyVector; /*Return the source route to its original configuration */
			(*theGraph)->addToGrid(thisSender);
			numberOfPackets += packets;
		}
	}
	else{
		printf("Error opening file\n");
	}
	fclose(thisFile);
	return numberOfPackets;
}


int main(int argc, char *argv[]) {	
	int sources, receivers, mules, dimension;
	if(argc != 5){
		cout << "Please try again and input sources, receivers, mules, dimension." << endl;
		return 0;
	}
	else{
		sources = atoi(argv[1]);
		receivers = atoi(argv[2]);
		mules = atoi(argv[3]);
		dimension = atoi(argv[4]);
		//Make a pointer to the Graph
		Graph *thisGraph = new Graph(dimension, sources, mules, receivers);
		if(DEBUG){
			cout << "Graph has been constructed." << endl;
		}
		//Build all the mules in the graph.
		addFromFile("prog5", sources, &thisGraph);
		for (int y = 0; y < mules; y++){
			Mule *aMule = new Mule((y + sources + 1));
			thisGraph->addToGrid(aMule);
		}
		//Build all the receivers in the graph.
		for (int z = 0; z < receivers; z++){
			Receiver *aReceiver = new Receiver((sources + mules + z + 1));
			thisGraph->addToGrid(aReceiver);
		}
		thisGraph->runSimulation(); /*redirect all calculations/simulations to the graph for simplification purposes*/
	}	
	return 0;
}

