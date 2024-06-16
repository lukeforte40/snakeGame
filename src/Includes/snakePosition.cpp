// Includes
    #include "snakePosition.h"
    #include "globalVariables.h"

using namespace std;
// Variables
    
// Functions
    bool checkSnakePosition(int x, int y){
        if (snakeHeadX == x && snakeHeadY == y)
        {
            return false;
        }
        while (snakeTailX != 0)
        {
            int i = 0;
            if (snakeTailX[i] == x)
            {
                if (snakeTailY[i] == y)
                {
                    return true;
                }
            }
            i++;
        }
    }