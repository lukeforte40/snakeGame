#if !defined(globalVariables_h)
#define globalVariables_h
    // Boundary sizing
    extern const int gameHeight;
    extern const int gameWidth;
    // Snakes head coordinates
    extern int snakeHeadX, snakeHeadY;
    // Fruit coordinates
    extern int fruitX, fruitY;
    // Player score
    extern int playerScore;
    // Snake tail arrays
    extern int snakeTailX[100], snakeTailY[100];
    // Snake tail lenght
    extern int tailLenght;
    // For storing snakes direction of travel
    enum snakeDirection {Stop = 0, Up, Down, Left, Right};
    // Snakes direction variable
    extern snakeDirection snakeDir;
    // Check if the game is over or not
    extern bool isGameOver;
#endif // globalVariables_h