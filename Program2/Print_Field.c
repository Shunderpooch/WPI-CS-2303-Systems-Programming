//Arthur Dooner, ajdooner@wpi.edu
#include <stdlib.h>
#include <stdio.h>
#include "BoardPlayersMore.h"

//Prints the Field
void printField(int Round){
    printf("\nSmashball is playing at round %d with %d Players from team 1 alive on the field \nand %d Players alive from team 2 on the field.\n\n", Round, PlayersAlive(1), PlayersAlive(2));
    //Generating the Column Labels
    for(int x = 0; x<WIDTH; x++){
        printf(" %2d", (x+1));
    }
    printf("\n+");
    for(int k1 =0; k1<WIDTH; k1++){
        printf("--+");
    }
    printf("\n");
    //Generating the Grid
    for(int y2=0; y2<HEIGHT; y2++){
        for(int x2=0; x2<WIDTH;x2++){
            if(gameArray[y2][x2]==0){
                printf("|  ");
            }
            else{
                printf("|%2d", gameArray[y2][x2]);
            }
        }
        printf("|%d\n+", (y2+1));
        for(int z=0; z<WIDTH; z++){
            printf("--+");
        }
        printf("\n");
    }

}
//Prints all of the information for the players on the Board
void printDirections(){
	printf("\n_____________________\n|PLAYER   |DIRECTION|\n|___________________|\n");
	for(int x=0; x<PLAYERSPERTEAM;x++){
		switch(team1[x].dir){
			
			case NORTH:
				printf("|%9d|NORTH    |\n|___________________|\n", team1[x].name);
				break;
			case SOUTH:
				printf("|%9d|SOUTH    |\n|___________________|\n", team1[x].name);
				break;
			case EAST:
				printf("|%9d|EAST     |\n|___________________|\n", team1[x].name);
				break;
			case WEST:
				printf("|%9d|WEST     |\n|___________________|\n", team1[x].name);
				break;
			case EMPTY:
				break;
		}
	}
	for(int y=0; y<PLAYERSPERTEAM;y++){
		switch(team2[y].dir){
			case NORTH:
				printf("|%9d|NORTH    |\n|___________________|\n", team2[y].name);
				break;
			case SOUTH:
				printf("|%9d|SOUTH    |\n|___________________|\n", team2[y].name);
				break;
			case EAST:
				printf("|%9d|EAST     |\n|___________________|\n", team2[y].name);
				break;
			case WEST:
				printf("|%9d|WEST     |\n|___________________|\n", team2[y].name);
				break;
			case EMPTY:
				break;
		}
	}
}
//Provides the Number of players that are alive on a given team.
int PlayersAlive(int Team){
	int FoundPlayers=0;
		switch (Team){
			case 1:
				for(int a=0; a<PLAYERSPERTEAM; a++){
					if (team1[a].isDead==0){
						FoundPlayers++;
					}
				}
				break;
			case 2:
				for(int b=0; b<PLAYERSPERTEAM; b++){
					if (team2[b].isDead==0){
						FoundPlayers++;
					}
				}
				break;
			default:
				printf("Invalid team number.");
				break;
		}
	return FoundPlayers;
}
