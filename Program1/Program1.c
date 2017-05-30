//Author Arthur Dooner, ajdooner@wpi.edu
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double logAverage, distance, Total, Average;
int px1, px2, py1, py2, i, numberOfPairs;

/*Takes the logarithm base 2 of the given double value*/
double logBase2(double x){
    return (log10(x)/log10(2));
}
/*Takes the euclidean distance between two points*/
double euclideanDistance(int x1, int x2, int y1, int y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2), 2));
}
/*Takes in a pair of coordinate points, calculating and returning the distance between the two.*/
double getCoordinatePair(int j){
        printf("Please input coordinate points %d and %d in the format x1 y1 x2 y2:\n", j*2+1, j*2+2);
        scanf("%d %d %d %d", &px1, &py1, &px2, &py2);
        distance= euclideanDistance(px1,px2,py1,py2);
        printf("The distance between these two points is %lf\n", distance);
        return distance;
}

/*Draws a graph with an accurate scale representing the ceil value of 
the number provided*/
void generateGraph(double num){
    int k;
    int roundedNum=ceil(num);
    double tempNum;
    printf("|\n|************************* %d\n", roundedNum);
    printf("|__________________________________________________\n");
    for(k=0; k<9; k++){
            double tempNum=(double)k*(double)roundedNum/4;
            if (tempNum<10){
                printf("%.2lf  ", tempNum);
            }
            else if (tempNum<100){
                printf("%.1lf  ", tempNum);
            }
            else{
                printf("%.1lf ", tempNum);
            }

        }
    printf("\n");
}
/*Runs the program and combines all of the functions together to achieve 
the desired functionality.*/
int main()
{
    printf("Please input the amount of pairs of coordinate points you want the program to use.\n");
    scanf("%d", &numberOfPairs);
    while (numberOfPairs<1){
        printf("That number of coordinate pairs is invalid. Please enter a valid one.\n");
        scanf("%d", &numberOfPairs);
    }
    for (i = 0; i<numberOfPairs; i++){
        Total+=getCoordinatePair(i);
    }
        Average=Total/(double)numberOfPairs;
        printf("The average of the Euclidean distances is %lf\n", Average);
	if(Average!=0){
        	logAverage=logBase2(Average);
      		printf("The logarithm base 2 of the average of Euclidian distance is %lf\n", logAverage);
        	generateGraph(logAverage);
        	return ceil(logAverage);
	}
	else{
		printf("The logarithm base 2 of the average of Euclideance distances is infinitely negative.\n This program does not have the resources to provide an infinite graph.");
		return 0;
	}
}
