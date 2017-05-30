#define LENGTH 18
#define WIDTH 12
#define SAMPLES 8

//Arthur J. Dooner, ajdooner@wpi.edu
typedef enum {Right, Left, Up, Down}direction;
int field[WIDTH][LENGTH];
void printField();
int motion(int nodeid, int row, int column, int direction);
