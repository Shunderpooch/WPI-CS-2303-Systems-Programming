//Arthur Dooner, ajdooner@wpi.edu
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "BoardPlayersMore.h"

//Convert an int from a dir
DIRECTION provideDIRfromInt(int Dir){
	DIRECTION actualDir;
	switch(Dir){
		case 0:
			actualDir=NORTH;
			return actualDir;
			break;
		case 1:
			actualDir=SOUTH;
			return actualDir;
			break;
		case 2:
			actualDir=EAST;
			return actualDir;
			break;
		case 3:
			actualDir=WEST;
			return actualDir;
			break;
		default:
			actualDir=EMPTY;
			return actualDir;
			break;
	}
}

//Generates an array in 2 dimensions, with 0s for all of the spaces without people
void generate2DimensionalArray(){
	srand(time(NULL));
    //Fills the Array with empty people
	for (int i = 0; i<HEIGHT; i++){
		for (int j = 0; j<WIDTH; j++){
			gameArray[i][j]=0;
			if(DEBUG){
                printf("Empty Player was added to %d Y and %d X\n", (i+1), (j+1));
			}
		}
	}
	//generates the Players on the field, each team together at nearly the same time
	for (int k = 0; k<PLAYERSPERTEAM; k++){
		int l = 0;
		int rand1, rand2;
		int randDir= rand() % 4;
		DIRECTION randDirection=provideDIRfromInt(randDir);
		//first team
		while (l==0){
            rand1= rand() % HEIGHT;
            rand2= rand() % WIDTH;
			if (gameArray[rand1][rand2]==0){
				PLAYER aPlayer= {(11+k), rand1, rand2, randDirection, 0, 1};
				team1[k]=aPlayer;
				gameArray[rand1][rand2]=aPlayer.name;
				if(DEBUG){
					printf("Player %d was added to location %dY and %dX on the field.\n", (11+k), (rand1+1), (rand2+1));
				}
				l=1;
			}
		}
		//second team
		int m = 0;
		while(m==0){
            rand1= rand() % HEIGHT;
			rand2= rand() % WIDTH;
			randDir=rand() % 4;
			randDirection=provideDIRfromInt(randDir);
			if (gameArray[rand1][rand2]==0){
				PLAYER aPlayerOtherTeam={(21+k), rand1, rand2, randDirection, 0, 2};
				team2[k]=aPlayerOtherTeam;
				gameArray[rand1][rand2]=aPlayerOtherTeam.name;
				if(DEBUG){
					printf("Player %d was added to location %dY and %dX on the field\n", (21+k), (rand1+1), (rand2+1));
				}
				m=1;
			}
		}
	}
}

