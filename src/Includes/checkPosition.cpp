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
        if (((snakeHeadX == x) && (snakeHeadY == y)))
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
        if (tailLenght == 0)
        {
            return false;
        }
        // find index of first matching value
        auto xIndex = find(snakeTailX.begin(),snakeTailX.end(), x);
        if (count(snakeTailX.begin(),snakeTailX.end(), x) == 0)
        {
            return false;
        }
        else{
            while (xIndex != snakeTailX.end())
            {
                // check if current x value has matching y variable
                if ((snakeTailY[xIndex - snakeTailX.begin()] == y) && (tailLenght > (xIndex - snakeTailX.begin())))
                {
                    return true;
                }
                // find next value index
                xIndex = find(xIndex + 1, snakeTailX.end(), x);
            }            
            return false;
        }
    }
    void checkCollision(){
        // Checks if the snakes head will collide with the wall
        if ((snakeHeadX == 0 || snakeHeadX == gameWidth - 2 || snakeHeadY == 0 || snakeHeadY == gameHeight - 2))
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
            snakeTailX.push_back(1);
            snakeTailY.push_back(1);
            generateFruitLoc();
        }
    }