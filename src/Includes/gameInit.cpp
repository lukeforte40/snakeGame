// Includes
    #include "gameInit.h"
    #include "globalVariables.h"
    #include "generateFruitLoc.h"
    #include "drawScreen.h"
    #include <iostream>
using namespace std;
// Function
    void gameInit(){
        cout << "Game Initializing..." << endl;
        isGameOver = false;
        snakeDir = Stop;
        snakeHeadX = gameWidth / 2;
        snakeHeadY = gameHeight / 2;
        generateFruitLoc();
        playerScore = 0;
        drawScreen();
    }
