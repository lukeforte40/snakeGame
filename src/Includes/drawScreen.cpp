// Includes
    #include "drawScreen.h"
    #include "globalVariables.h"
    #include "clearScreen.h"
    #include <iostream>

using namespace std;

// Functions
    void drawHorizontal(){
        for (int i = 0; i < gameWidth; i++){
            cout << "-";
        }
        cout << endl;
    }
    void drawContent(){
        for (int i = 0; i < gameHeight; i++){
            // Drawing left wall
            cout << "|";
            // Drawing the inside of the game
            for (int i = 0; i < gameHeight - 2; i++){
                for (int j = 0; j < gameWidth; j++)
                {
                    // Check what belongs at x,y on screen
                    checkContent(j, i);
                }
            }
            // Drawing the right wall
            cout << "|" << endl;
        }
    }
    void checkContent(int x, int y){
        // If empty space
        if (snakeHeadX != x || snakeHeadY != y && fruitX != x || fruitY != y)
        {
            cout << ' ';
        }
        // Print snake head
        if (snakeHeadX == x && snakeHeadY == y)
        {
            cout << 'O';
        }
        // Print fruit
        if (fruitX == x && fruitY == y)
        {
            cout << "#";
        }
        
    }
    void drawScreen(){
        clearScreen();
        // Draw the top wall
        drawHorizontal();
        // Draw the interior and sides of game
        drawContent();
        // Draw the bottom wall
        drawHorizontal();
        isGameOver = true;
    }