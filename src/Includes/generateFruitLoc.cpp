// Includes
    #include "generateFruitLoc.h"
    #include "globalVariables.h"
    #include "snakePosition.h"
    #include <iostream>

using namespace std;
// Variables
    
// Functions
    void generateFruitLoc(){
        fruitX = rand() % gameWidth;
        fruitY = rand() % gameHeight;
        while (checkSnakePosition(fruitX, fruitY))
        {
            fruitX = rand() % gameWidth;
            fruitY = rand() % gameHeight;
        }
    }