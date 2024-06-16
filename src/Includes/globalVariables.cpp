// Includes
#include <vector>

using namespace std;
// Global Varaibles
    // Boundary sizing
    extern const int gameHeight;
    extern const int gameWidth;
    // Snakes head coordinates
    extern int snakeHeadX, snakeHeadY;
    // Fruit coordinates
    extern int fruitX, fruitY;
    // Player score
    extern int playerScore;
    // Snake tail arrays
    extern vector<int> snakeTailX;
    extern vector<int> snakeTailY;
    // Snake tail lenght
    extern int tailLenght;
    // For storing snakes direction of travel
    enum snakeDirection {Stop = 0, Up, Down, Left, Right};
    // Snakes direction variable
    extern snakeDirection snakeDir;
    // Check if the game is over or not
    extern bool isGameOver;
// Functions
    