// Includes
    #include "gameInit.h"
    #include "globalVariables.h"
    #include <iostream>

using namespace std;

// Function
    void gameInit(){
        isGameOver = false;
        snakeDir = Stop;
        snakeHeadX = gameWidth / 2;
        snakeHeadY = gameHeight / 2;
        fruitX = rand() % gameWidth;
        fruitY = rand() % gameHeight;
        playerScore = 0;
        cout << "Game Initializing..." << endl;
    }
