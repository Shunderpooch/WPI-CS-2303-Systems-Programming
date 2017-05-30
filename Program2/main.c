//Arthur Dooner, ajdooner@wpi.edu
//Program 2, CS2303
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BoardPlayersMore.h"

int runSeveralRounds(int NumberOfRounds){
	for(int g=1; g<NumberOfRounds;g++){
		if(PlayersAlive(1)==0){
			printField(g);
			printf("Team 2 has successfully defeated team 1 in Smashball in round %d.\n", g);
			return 2;
		}
		else if(PlayersAlive(2)==0){
			printField(g);
			printf("Team 1 has successfully defeated team 2 in Smashball in round %d.\n", g);
			return 1;
		}
		else{
			runARound(g);
		}
	}
	return 0;

}

int main(){
	int WINNER=0;
    generate2DimensionalArray();
    printField(0);
    printDirections();
    WINNER=runSeveralRounds(ENDROUNDS);
    if(WINNER==0){
	printField(ENDROUNDS);
	printDirections();
    	printf("No team won this match in the %d rounds provided.\n", ENDROUNDS);
    }
    return WINNER;
}
