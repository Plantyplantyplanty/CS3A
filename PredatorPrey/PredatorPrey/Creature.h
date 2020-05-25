#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <cassert>
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>"

using namespace std;

const float CELL_SIZE = 35; //the cell sizes of the grid
const int G_SIZE = 22; //The size of the grid
enum type{CREATURE, WALL_CREATURE, PREY, PREDATOR}; 
//The flags for signalling the type of Creature

/*Where the Creature is in the grid*/
struct location {
	location(int i = 0, int j = 0) :_i(i), _j(j){}
	unsigned int _i; //row 
	unsigned int _j; //column
};


class Creature{
public:
	Creature(unsigned x, unsigned y);
	/*Constructor: accepts a pair of coordinates which specify the Creature's location*/

	/*Moving*/
	virtual bool move(Creature* pos[][G_SIZE]);
	//Move the Creature
	bool move_to(Creature* pos[][G_SIZE], const location coords);
	//Moves the Creature to these coordinates
	void reset_moved();
	//Makes moved = false

	/*Finding*/
	location find_blank(Creature* pos[][G_SIZE]);
	//Finds the blank spaces around the Creature
	Vector<location> find_this_creature(Creature* pos[][G_SIZE], const type find);
	//Finds the spaces around the Creature of type "find"
	Vector<location> find_not_this_creature(Creature* pos[][G_SIZE], const type find);
	//Finds the spaces around the Creature not of type "find". Unused?

	virtual bool breed(Creature* pos[][G_SIZE], const location coords);
	//Breeds the Creature
	virtual void kill(Creature* pos[][G_SIZE]);
	//Kills the Creature, deleting it from the matrix

	bool get_moved() const { return _moved; }
	//Returns if the Creature has moved
	virtual void print() { cout << "x"; }
	//Unused function used in testing

	virtual int typeOf() { return CREATURE; }
	//Returns what type of Creature this is
	virtual void draw(sf::RenderWindow& window, location loc);

	/*stream operators*/
	friend ostream& operator <<(ostream& outs, const Creature &c);
	friend istream& operator >>(istream& ins,  Creature &c); //unused

private:
	location _location; //The location of the Creature
	bool _moved; //Whether the Creature has moved this "step"
};

#endif
