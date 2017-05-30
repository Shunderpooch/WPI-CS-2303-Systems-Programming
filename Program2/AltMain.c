//Arthur Dooner, ajdooner@wpi.edu
//Program 2, CS2303
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 25
#define HEIGHT 25
#define PLAYERSPERTEAM 9
#define DEBUG 0
#define ENDROUNDS 100
#define FREQUENCYOFPRINT 10

typedef enum{NORTH,SOUTH,EAST,WEST,EMPTY}DIRECTION;

//Provides a structure for the player
struct Player{
    int name;
    int locY;
    int locX;
    DIRECTION dir;
    int isDead;
    int team;
} Player;
//names the struct we just made
typedef struct Player PLAYER;
//creates the 2 Dimensional integer gameArray
int gameArray[HEIGHT][WIDTH];
//Creates both teams as arrays of PLAYER
PLAYER team1[PLAYERSPERTEAM];
PLAYER team2[PLAYERSPERTEAM];


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
			default:
				printf("|%9d|DEAD     |\n|___________________|\n", team1[x].name);
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
			default:
				printf("|%9d|DEAD     |\n|___________________|\n", team2[y].name);
				break;

		}
	}
}
PLAYER makeMove(PLAYER thisPlayer, int dY, int dX);
//Performs the actions of one player and returns the new attributes of the player.
//This specifically checks for a bounce, then moves the player.
PLAYER OverallMove(PLAYER thisPlayer){
	int dY=0;
	int dX=0;
	switch(thisPlayer.dir){
		case NORTH:
			if(thisPlayer.locY==0){
				thisPlayer.dir=SOUTH;
				dY=1;
			}
			else{
				dY=-1;
			}
			break;
		case SOUTH:
			if(thisPlayer.locY==(HEIGHT-1)){
				thisPlayer.dir=NORTH;
				dY=-1;
			}
			else{
				dY=1;
			}
			break;
		case EAST:
			if(thisPlayer.locX==(WIDTH-1)){
				thisPlayer.dir=WEST;
				dX=-1;
				}
			else{
				dX=1;
			}
			break;
		case WEST:
			if(thisPlayer.locX==0){
				thisPlayer.dir=EAST;
				dX=1;
			}
			else{
				dX=-1;
			}
			break;
		default:
			printf("There is a dead player attempting to move. It's name is %d.\n", thisPlayer.name);
			return thisPlayer;
			break;
	}
	if(thisPlayer.name==gameArray[thisPlayer.locY][thisPlayer.locX]){
		gameArray[thisPlayer.locY][thisPlayer.locX]=0;
	}
	thisPlayer=makeMove(thisPlayer, dY, dX);
	return thisPlayer;
}

PLAYER makeMove(PLAYER thisPlayer, int dY, int dX){
	//is it an empty space?
	if (gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)]==0){
		gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)]=thisPlayer.name;
		thisPlayer.locY+=dY;
		thisPlayer.locX+=dX;
        if (DEBUG){
			printf("Player %d moved to %dY, %dX.\n", thisPlayer.name, (thisPlayer.locY+1), (thisPlayer.locX+1));
		}
		return thisPlayer;
	}
	//is an enemy player there?
	else if((gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)]<20 && thisPlayer.team==2)||(gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)]>20 && thisPlayer.team==1)){
		int tempPerson=gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)];
		gameArray[(thisPlayer.locY+dY)][(thisPlayer.locX+dX)]=thisPlayer.name;
		thisPlayer.locY+=dY;
		thisPlayer.locX+=dX;
		if (DEBUG){
			printf("Player %d got SMASHED by Player %d at %dY, %dX.\n", tempPerson, thisPlayer.name, (thisPlayer.locY+1), (thisPlayer.locX+1));
		}
		if(tempPerson>20){
			tempPerson-=21;
			PLAYER killedPerson={(tempPerson+21), -1, -1, EMPTY, 1, 2};
			team2[tempPerson]=killedPerson;
			if(DEBUG==1){
                printf("Player %d is now dead with location %dY %dX, EMPTY direction, and with isDead equal to %d", team2[tempPerson].name, team2[tempPerson].locY, team2[tempPerson].locX, team2[tempPerson].isDead);
			}
		}
		else{
			tempPerson-=11;
			PLAYER killedPerson={(tempPerson+11), -1, -1, EMPTY, 1, 1};
			team1[tempPerson]=killedPerson;
            if(DEBUG){
                printf("Player %d is now dead with location %dY %dX, EMPTY direction, and with isDead equal to %d", team1[tempPerson].name, team1[tempPerson].locY, team1[tempPerson].locX, team1[tempPerson].isDead);
			}
		}
		return thisPlayer;
	}
	//So they're on the same team?
	else {
		thisPlayer.locX+=dX;
		thisPlayer.locY+=dY;
		//We have to jump again.
		return OverallMove(thisPlayer);
	}
	return thisPlayer;
}


//performs the actions that take place every round.
void runARound(int Round){
	for(int i=0; i<PLAYERSPERTEAM; i++){
		if (team1[i].isDead==0){
			team1[i]=OverallMove(team1[i]);
		}
		if (team2[i].isDead==0){
			team2[i]=OverallMove(team2[i]);
		}
	}
	if (DEBUG){
        printf("Smashball has completed round %d\n", Round);
	}
	if (Round%FREQUENCYOFPRINT==0){
		printField(Round);
		printDirections();
	}
	return 0;
}
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
    srand(time(NULL));
    generate2DimensionalArray();
    printField(0);
    printDirections();
    WINNER=runSeveralRounds(ENDROUNDS);
    if(WINNER==0){
    	printf("No team won this match in the %d rounds provided.\n", ENDROUNDS);
    }
    return WINNER;
}
