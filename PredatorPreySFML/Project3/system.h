
#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Grid.h"

using namespace std;
class System
{
public:
    System();
    void Step();
    //Draws this window
    void Draw(sf::RenderWindow& widnow);
private:
    Grid _g; //The grid we are drawing
    unsigned int generation; //The generation creature breeding
};

#endif // SYSTEM_H