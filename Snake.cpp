#include <conio.h>
#include <iostream>
#include <windows.h>

// Variables
// Boundary sizing
const int gameHeight = 80;
const int gameWidth = 20;
// Snakes head coordinates
int snakeHeadX, snakeHeadY;
// Fruit coordinates
int fruitX, fruitY;
// Player score
int playerScore;
// Snake tail arrays
int snakeTailX[100], snakeTailY[100];
// Snake tail lenght
int tailLenght;
// For storing snakes direction of travel
enum snakeDirection {Stop = 0, Up, Down, Left, Right};
// Snakes direction variable
snakeDirection snakeDir;
// Check if the game is over or not
bool isGameOver;

// Functions
void gameInit(){
    isGameOver = false;
    snakeDir = Stop;
    snakeHeadX = gameWidth / 2;
    snakeHeadY = gameHeight / 2;
    fruitX = rand() % gameWidth;
    fruitY = rand() % gameHeight;
    playerScore = 0;
}
