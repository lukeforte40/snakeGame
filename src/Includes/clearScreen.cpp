#include <iostream>
#include "clearScreen.h"
void clearScreen(){
    #ifdef __unix__
        system("clear"); // for unix
    #endif
    #if defined(__32win) || defined(WIN32)
        system("cls"); // for windows
    #endif
}