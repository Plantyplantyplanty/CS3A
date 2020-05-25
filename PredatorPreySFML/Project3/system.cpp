
#include "system.h"
#include <iostream>
#include "constants.h"

System::System()
{
    _g.fill_grid(100, 5);
    cout << "\nIntial Grid:\n";
    cout << _g << endl;
    generation = 1;
    cout << generation << endl;
}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step() {
    _g.Step();
    _g.Breed();
    _g.Kill();
    generation++;
    cout << "Generation:" << generation << endl;
}


void System::Draw(sf::RenderWindow& window) {
    _g.Draw(window);

}