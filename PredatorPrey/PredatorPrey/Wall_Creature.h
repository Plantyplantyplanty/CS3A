#ifndef WALL_C_H
#define WALL_C_H
#include "Creature.h"

//These do nothing. They are immortal, dumb, and still. 
class Wall_Creature : public Creature{

public:
	Wall_Creature(unsigned int x, unsigned int y);

	bool move(Creature* pos[][G_SIZE]);
	bool breed(Creature* pos[][G_SIZE], location coords);
	void kill(Creature* pos[][G_SIZE]);

	int typeOf() { return WALL_CREATURE; }

	void print() { cout << "W"; }
	
	//Draws the creature at this location
	void draw(sf::RenderWindow& window, location loc);
	friend ostream& operator <<(ostream& outs, Wall_Creature c);
};

#endif