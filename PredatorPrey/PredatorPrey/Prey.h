#pragma once
#include "Creature.h"


class Prey :public Creature{

public:
	const int TIME_TO_BREED = 4;

	Prey(unsigned int x, unsigned int y);
	bool move(Creature* pos[][G_SIZE]);
	bool breed(Creature* pos[][G_SIZE], location coords);

	//Called when the creature is killed
	void die(Creature* pos[][G_SIZE]); 
	void kill(Creature* pos[][G_SIZE]);

	int typeOf() { return PREY; }
	void print() { cout << "o"; }

	//Draws the creature at this location
	void draw(sf::RenderWindow& window, location loc);
	friend ostream& operator <<(ostream& outs, const Prey& c);

private:
	int _time; //time elapsed since breeding
};

