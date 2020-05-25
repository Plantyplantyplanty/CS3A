/*
 * Author: Marisa Persaud
 * Project: Predator/Prey SFML
 * Purpose: Make Predator/Prey into a graphics-based program
 *
 * //NOTE: an example of programming style, formatting, and testing for beginners.
 */

#include "animate.h"
#include "constants.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>


int main(){
    animate game;
    game.run();
    cout << endl << endl << "------ MAIN EXITING --------------------------" << endl;
    return 0;
}