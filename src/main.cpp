// Includes
    #include "Includes/globalVariables.h"
    #include "Includes/updateGame.h"
    #include <iostream>
    #include <vector>

using namespace std;
// Global variables
    // Boundary sizing
    const int gameHeight = 20;
    const int gameWidth = 80;
    // Snakes head coordinates
    int snakeHeadX, snakeHeadY;
    // Fruit coordinates
    int fruitX, fruitY;
    // Player score
    int playerScore;
    // Snake tail arrays
    vector<int> snakeTailX, snakeTailY;
    // Snake tail lenght
    int tailLenght;
    // Snakes direction variable
    snakeDirection snakeDir;
    // Check if the game is over or not
    bool isGameOver;

// Main function
    int main(){
        play();
        return 0;
    }
