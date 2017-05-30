//Arthur Dooner, ajdooner@wpi.edu
#include <stdlib.h>
#include <stdio.h>
int input, Average, Total, i, output;
int stopNum=9999;

/*This function allows the user to input a number for this program.*/
int takeInANumber(int index){
  printf("Please provide the number at index %d for your input.\nInput stops when you enter %d.\n", index, stopNum);
  scanf("%d", &input);
  return input;
}

/*This function calculates and returns the average of an arbitrary amount of numbers until the integer 9999 is passed to it.*/
int calculateAverageXNumbers(){
  while(output!=stopNum){
    output=takeInANumber(++i);
    if(output!=stopNum){
      Total+=output;
    }
    else{
      i--;
    }
  }
  Average=(Total/i);
  printf("The Average of your numbers is %d. Thank you for using this program.", Average);
}
//This runs my program
int main(){
  calculateAverageXNumbers();
}
