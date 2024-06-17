// Includes
    #include "gameInit.h"
    #include "globalVariables.h"
    #include "updateGame.h"
    #include "drawScreen.h"
    #include <iostream>
    #include <thread>
using namespace std;
// Function
    void gameInit(){
        cout << "Game Initializing..." << endl;
        isGameOver = false;
        snakeDir = Up;
        snakeHeadX = gameWidth / 2;
        snakeHeadY = gameHeight / 2;
        generateFruitLoc();
        playerScore = 0;
        drawScreen();
        thread thr(tick);
        thr.join();
    }
