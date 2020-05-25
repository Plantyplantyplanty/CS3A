#pragma once
#include "Creature.h"
#include "Prey.h"

class Predator :public Creature{
public:
	const int TIME_TO_BREED = 8; //Steps until "breed" is called
	const int STARVATION = 3;    //Steps until death from starvation

	Predator(unsigned int x, unsigned int y);

	bool move(Creature* pos[][G_SIZE]);
	bool breed(Creature* pos[][G_SIZE], location coords);
	void kill(Creature* pos[][G_SIZE]);

	int typeOf() { return PREDATOR; } //Returns a flag signalling what type of object this is
	void print() { cout << "X"; } //The output

	//Draws the creature at this location
	void draw(sf::RenderWindow& window, location loc);
	friend ostream& operator <<(ostream& outs, const Predator& c);

private:
	unsigned int _time_to_breed; //how many steps have passed since the creature has bred
	unsigned int _starve; //how many steps since the creature has eaten
};


