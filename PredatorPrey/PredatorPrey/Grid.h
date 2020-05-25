#ifndef GRID_H
#define GRID_H

#include "Creature.h"
#include "Prey.h"
#include "Predator.h"
#include "Wall_Creature.h"

class Grid{
public:
	/*Initializes all members of _grid to nullptr*/
	Grid();

	/*Big Three and helper*/
	Grid(const Grid &og);
	Grid& operator =(const Grid &og);
	~Grid();
	void copyGrid(const Grid& og);

	/*Initialize _grid with the given number of prey and predators*/
	void fill_grid(int num_prey, int num_preds);

	/*Interact with all creatures*/
	//Calls their move
	void Step(); 
	//Calls their breed
	void Breed();
	//Calls their kill
	void Kill();

	//Draws each creature in a grid
	void Draw(sf::RenderWindow& window);
	//Prints to console
	friend ostream& operator <<(ostream& outs, Grid g);

private:
	Creature* _grid[G_SIZE][G_SIZE];

	void reset_moved();
	//Resets all of the creature's "_moved" bools to "false"
	void fill_wall_creatures();
	//Fills in the wall creatures when intializing
	location get_empty_space();
	//gets an empty space in the grid
	void delete_grid();
};

#endif

