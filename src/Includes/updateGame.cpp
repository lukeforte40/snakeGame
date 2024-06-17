// Includes
    #include "updateGame.h"
    #include "globalVariables.h"
    #include "checkPosition.h"
    #include "drawScreen.h"
    #include <iostream>
    #include <thread>
    #include <chrono>
using namespace std;
// Variables
    
// Functions
    void clearScreen(){
        #ifdef __unix__
            system("clear"); // for unix
        #endif
        #if defined(__32win) || defined(WIN32)
            system("cls"); // for windows
        #endif
    }
    void generateFruitLoc(){
        fruitX = rand() % gameWidth;
        fruitY = rand() % gameHeight;
        while (checkSnakePosition(fruitX, fruitY))
        {
            fruitX = rand() % gameWidth;
            fruitY = rand() % gameHeight;
        }
    }
    void tick(){
        while (!isGameOver)
        {
            getUserInput();
            move();
            checkCollision();
            drawScreen();
            this_thread::sleep_for(chrono::seconds(1/ tailLenght + 1));
        }
    }
    void move(){
        if (tailLenght != 0)
        {
            // Setting the first array index to the current snake position
            snakeTailX[0] = snakeHeadX;
            snakeTailY[0] = snakeHeadY;
            // Looping through ever item excpet the first and adding the next x,y value to the current.
            for (int i = 0; i > snakeTailX.size() ; i++)
            {
                snakeTailX[i] = snakeTailX[i+1];
                snakeTailY[i] = snakeTailY[i+1];
            }
        }
        switch (snakeDir)
        {
        case Up:
            snakeHeadY--;
            break;
        case Down:
            snakeHeadY++;
            break;
        case Left:
            snakeHeadX--;
            break;
        case Right:
            snakeHeadX++;
            break;
        default:
            break;
        }
    }
