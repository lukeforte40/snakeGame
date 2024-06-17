// Includes
    #include "updateGame.h"
    #include "globalVariables.h"
    #include "checkPosition.h"
    #include "drawScreen.h"
    #include <iostream>
    #include <thread>
    #include <chrono>
    #ifdef __unix__ // for unix
        #include <cstdio>
        #include <unistd.h>
        #include <termios.h>
    #endif
    #if defined(__32win) || defined(WIN32)
        #include <conio.h>
    #endif

using namespace std;
// Variables
    char c;
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
    void tick(){
        // Run Game
        do
        {
            move();
            checkCollision();
            drawScreen();
            switch (snakeDir)
            {
            case Up:
            this_thread::sleep_for(chrono::milliseconds(500));
                break;
            case Down:
            this_thread::sleep_for(chrono::milliseconds(700));
                break;
            default:
            this_thread::sleep_for(chrono::milliseconds(100));
                break;
            }
        } while (!isGameOver);
    }
    void move(){
        if (tailLenght != 0)
        {
            // Setting the first array index to the current snake position
            snakeTailX[0] = snakeHeadX;
            snakeTailY[0] = snakeHeadY;
            // Looping through every item excpet the first and adding the current x,y value to the next.
            for (int i = tailLenght; i > 0; i--)
            {
                snakeTailX[i] = snakeTailX[i - 1];
                snakeTailY[i] = snakeTailY[i - 1];
            }
        }
        switch (snakeDir)
        {
        case Up:
            snakeHeadY--;
            break;
        case Down:
            snakeHeadY++;
            break;
        case Left:
            snakeHeadX--;
            break;
        case Right:
            snakeHeadX++;
            break;
        default:
            break;
        }
    } 
    void getUserInput(){
        #ifdef __unix__ // for unix
            do
            {
                read(STDIN_FILENO, &c, 1);
                switch (c)
                {
                case 'w':
                    snakeDir = Up;
                    break;
                case 's':
                    snakeDir = Down;
                    break;
                case 'a':
                    snakeDir = Left;
                    break;
                case 'd':
                    snakeDir = Right;
                    break;
                default:
                    break;
                }
            }while (!isGameOver);

        #endif
        #if defined(__32win) || defined(WIN32) // for windows
            do
            {
                if (_kbhit())
                {
                    switch (_getch())
                    {
                    case 'w':
                        snakeDir = Up;
                        break;
                    case 's':
                        snakeDir = Down;
                        break;
                    case 'a':
                        snakeDir = Left;
                        break;
                    case 'd':
                        snakeDir = Right;
                        break;
                    default:
                        break;
                    }
                }
            }while (!isGameOver);
        #endif
    }
    void play(){
        cout << "press W, A, S, or D to Start." << endl;
        cin >> c;
        isGameOver = false;
        snakeDir = Up;
        snakeHeadX = gameWidth / 2;
        snakeHeadY = gameHeight / 2;
        generateFruitLoc();
        playerScore = 0;
        drawScreen();
        #ifdef __unix__ // for unix
            // Capture current terminal state
                struct termios origTerminal;
                tcgetattr(STDIN_FILENO, &origTerminal);
            // Turn off ECHO and enable raw mode
                struct termios rawTerminal;
                tcgetattr(STDIN_FILENO, &rawTerminal);
                rawTerminal.c_lflag &= ~(ECHO | ICANON);
                tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTerminal);
        #endif
        thread thr1(tick);
        thread thr2(getUserInput);
        thr1.join();
        thr2.join();
        #ifdef __unix__ // for unix
            // Reset terminal to original state
                tcsetattr(STDIN_FILENO, TCSAFLUSH, &origTerminal);
        #endif
    }
