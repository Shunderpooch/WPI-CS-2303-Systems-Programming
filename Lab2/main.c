//Arthur J. Dooner, ajdooner@wpi.edu
#include "motion.h"
#include <stdio.h>

//Clears the board, generates each movement of a player, and prints the board each time.
int main(){
	//Runs through all the samples
	for(int a=0; a<SAMPLES; a++){
		//Clears the board
		for(int x=0; x<WIDTH; x++){
			for(int y=0; y<LENGTH; y++){
				field[x][y]=0;
			}
		}
		int nodeid, row, column, direction;
		printf("Please provide the criteria for the printout in the form: \n nodeid row column direction\n");
		//finds input and moves
		scanf("%d %d %d %d", &nodeid, &row, &column, &direction);
		motion(nodeid, row, column, direction);
		printField();
	}
}
