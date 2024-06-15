// Includes
    #include "Includes/globalVariables.h"
    #include "Includes/gameInit.h"
    #include "Includes/drawScreen.h"
    
// Global variables
    // Boundary sizing
    const int gameHeight = 80;
    const int gameWidth = 20;
    // Snakes head coordinates
    int snakeHeadX, snakeHeadY;
    // Fruit coordinates
    int fruitX, fruitY;
    // Player score
    int playerScore;
    // Snake tail arrays
    int snakeTailX[100], snakeTailY[100];
    // Snake tail lenght
    int tailLenght;
    // Snakes direction variable
    snakeDirection snakeDir;
    // Check if the game is over or not
    bool isGameOver;

// Main function
    int main(){
        gameInit();
        
        return 0;
    }
