//Arthur Dooner, ajdooner@wpi.edu
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
void printField(int Round);
void printDirections();
DIRECTION provideDIRfromInt(int Dir);
void generate2DimensionalArray();
int PlayersAlive(int Team);
PLAYER OverallMove(PLAYER thisPlayer);
PLAYER makeMove(PLAYER thisPlayer, int dY, int dX);
void runARound(int Round);
