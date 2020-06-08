/*
 * Author: Marisa 
 * Project: Graphing Calc Check-in one
 * Purpose: Implement phase 2 of the graphing calc
 * Notes: It should be a crime to have school during late springtime.
 */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "animate.h"
using namespace std;

int main()
{

    animate game;
    game.run();
    cout << endl << endl << "------ MAIN EXITING --------------------------" << endl;
    //_CrtDumpMemoryLeaks();
    return 0;
}