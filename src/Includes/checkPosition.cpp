// Includes
    #include "checkPosition.h"
    #include "globalVariables.h"

using namespace std;
// Variables
    
// Functions
    bool checkSnakePosition(int x, int y){
        if (snakeHeadX == x && snakeHeadY == y)
        {
            return true;
        }
        int i = 0;
        while (snakeTailX[i] != 0)
        {
            if (snakeTailX[i] == x && snakeTailY[i] == y)
            {
                return true;
            }
            i++;
        }
        return false;
    }
    bool checkFruitPosition(int x, int y){
        if (fruitX == x && fruitY == y)
        {
            return true;
        }
        return false;
    }