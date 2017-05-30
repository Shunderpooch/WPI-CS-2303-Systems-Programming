//Arthur Dooner, ajdooner@wpi.edu
#include <stdlib.h>
#include <stdio.h>
#include "BoardPlayersMore.h"

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
}
