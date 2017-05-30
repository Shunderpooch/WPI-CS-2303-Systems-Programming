//Arthur J. Dooner, ajdooner@wpi.edu
#include "motion.h"
#include <stdio.h>
//Prints the Field
void printField(){
    //Generating the Column Labels
    for(int x = 0; x<WIDTH; x++){
        printf(" %3d", x);
    }
    printf("\n-");
    for(int k1 =0; k1<WIDTH; k1++){
        printf("----");
    }
    printf("\n");
    //Generating the Grid
    for(int y2=0; y2<LENGTH; y2++){
        for(int x2=0; x2<WIDTH;x2++){
            if(field[x2][y2]==0){
                printf("|   ");
            }
            else{
                printf("|%3d", field[x2][y2]);
            }
        }
        printf("|%d\n-", y2);
        for(int z=0; z<WIDTH; z++){
            printf("----");
        }
        printf("\n");
    }

}
