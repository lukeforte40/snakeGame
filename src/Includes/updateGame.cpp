// Includes
    #include "updateGame.h"
    #include "globalVariables.h"
    #include "checkPosition.h"
    #include <iostream>
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