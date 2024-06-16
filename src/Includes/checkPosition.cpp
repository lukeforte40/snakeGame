// Includes
    #include "checkPosition.h"
    #include "globalVariables.h"
    #include <algorithm>
    #include <bits/stdc++.h>

using namespace std;
// Variables
    
// Functions
    bool checkSnakePosition(int x, int y){
        if (snakeHeadX == x && snakeHeadY == y)
        {
            return true;
        }
        checkTail(x, y);
        return false;
    }
    bool checkFruitPosition(int x, int y){
        if (fruitX == x && fruitY == y)
        {
            return true;
        }
        return false;
    }
    bool checkTail(int x, int y){
        if (snakeTailX.empty())
        {
            return false;
        }
        // find index of first matching value
        auto xIndex = find(snakeTailX.begin(),snakeTailX.end(), x);
        switch (count(snakeTailX.begin(),snakeTailX.end(), x))
        {
        case 0:
            return false;
            break;
        case 1:
            // check if current x value has matching y variable
            if (snakeTailY[xIndex - snakeTailX.begin()] == y)
            {
                return true;
            }
            return false;
        default:
            while (xIndex != snakeTailX.end())
            {
                // check if current x value has matching y variable
                if (snakeTailY[xIndex - snakeTailX.begin()] == y)
                {
                    return true;
                }
                // find next value index
                xIndex = find(xIndex + 1, snakeTailX.end(), x);
            }            
            return false;
            break;
        }
    }