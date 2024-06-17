// Includes
    #include "checkPosition.h"
    #include "updateGame.h"
    #include "globalVariables.h"
    #include <algorithm>
    #include <bits/stdc++.h>

using namespace std;
// Variables
    
// Functions
    bool checkSnakePosition(int x, int y){
        if ((snakeHeadX == x && snakeHeadY == y))
        {
            return true;
        }
        else if(checkTail(x, y)){
            return true;
        }
        return false;
    }
    bool checkFruitPosition(int x, int y){
        if ((fruitX == x && fruitY == y))
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
    void checkCollision(){
        // Checks if the snakes head will collide with the wall
        if ((snakeHeadX == 0 || snakeHeadX == gameWidth || snakeHeadY == 0 || snakeHeadY == gameHeight))
        {
            isGameOver = true;
        }
        // Checks if the snakes head will collide with its own tail
        else if (checkTail(snakeHeadX, snakeHeadY))
        {
            isGameOver = true;
        }
        // Checks if the snakes head lands on a fruit
        else if (checkFruitPosition(snakeHeadX, snakeHeadY))
        {
            tailLenght++;
            playerScore += 10;
            snakeTailX.push_back(snakeHeadX);
            snakeTailY.push_back(snakeHeadY);
            generateFruitLoc();
        }
    }