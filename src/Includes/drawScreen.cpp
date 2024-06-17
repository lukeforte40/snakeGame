// Includes
    #include "drawScreen.h"
    #include "globalVariables.h"
    #include "updateGame.h"
    #include "checkPosition.h"
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
        for (int i = 0; i < gameHeight - 2; i++){
            // Drawing left wall
            cout << "|";
            // Drawing the inside of the game
                for (int j = 0; j < gameWidth - 2; j++)
                {
                    // Check what belongs at x,y on screen
                    checkContent(j, i);
                }
            // Drawing the right wall
            cout << "|" << endl;
            }
        }
    void checkContent(int x, int y){
        // If empty space
        if (!(checkFruitPosition(x, y) || checkSnakePosition(x, y)))
        {
            cout << ' ';
        }
        // Print fruit
        else if (checkFruitPosition(x, y))
        {
            cout << '#';
        }
        // Print snake tail
        else if (checkTail(x, y))
        {
            cout << "0";
        }
        // Print snake head
        else
        {
            cout << 'O';
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
    }