//Arthur J. Dooner, ajdooner@wpi.edu
#include "motion.h"
#include <stdio.h>

//Moves the item with the given nodeid from the first row and column continuously to the next in the direction provided
//until it reaches the edge of the board.
int motion (int nodeid, int row, int column, int direction){
	field[row][column]=nodeid;
	switch (direction){
		//This is right
		case 0: 
			if(row<(WIDTH-1)) {
				nodeid++;
				row++;
				motion(nodeid, row, column, direction);
			}
			break;
		//This is left
		case 1:
			if(row>0){
				nodeid++;
				row--;
				motion(nodeid, row, column, direction);
			}
			break;
		//This is up
		case 2:
			if(column>0){
				nodeid++;
				column--;
				motion(nodeid, row, column, direction);
			}
			break;
		//This is down
		case 3:
			if(column<(LENGTH-1)){
				nodeid++;
				column++;
				motion(nodeid, row, column, direction);
			}
			break;
	}
	return 0;
}
