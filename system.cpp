#include "system.h"
#include <iostream>

#include "constants.h"
System::System(Graph_info* info): _info(info), _g(info){}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(){
    //Update the graph
    _g.update();

}


void System::Draw(sf::RenderWindow& window){
    //Draw the graph
    _g.draw(window);
}
