#include "Creature.h"

//Assigns the Creature's location struct to x and y
//Does not guarantee that this space in the grid only contains this creature!
Creature::Creature(unsigned x, unsigned y) {
	//Checks if location is within the grid
	assert(x < G_SIZE && y < G_SIZE && x >= 0 && y >= 0);

	_location._i = x;
	_location._j = y;

	_moved = false;
}

/*Moves the Creature to another location inside the grid if there is space*/
bool Creature::move(Creature* pos[][G_SIZE]) {
	return move_to(pos, find_blank(pos));
}

/*Moves the Creature to these coordinates*/
bool Creature::move_to(Creature* pos[][G_SIZE], const location coords) {
	

	//If the coordinates are within the grid and the position isn't occupied
	if (coords._i >= 0 && coords._j >= 0 && coords._i < G_SIZE && coords._j < G_SIZE && pos[coords._i][coords._j] == nullptr) {
		//Current location = nullptr
		pos[_location._i][(_location._j)] = nullptr;

		//set this object's coordinates to the passed coordinates
		_location = coords;

		//Put this object in the passed location
		pos[_location._i][(_location._j)] = this;

		_moved = true;

		return true;
	}
	else {
		return false;
	}

}

/*Resets if the Creature has moved to false*/
void Creature::reset_moved() {
	_moved = false;
}

/*Finds the blank spaces around a Creature*/
location Creature::find_blank(Creature* pos[][G_SIZE]) {
	Vector<location> blank;
	for (int i = (_location._i - 1); i <= _location._i + 1; i++) {
		for (int j = (_location._j - 1); j <= (_location._j + 1); j++){
			if (pos[i][j] == nullptr) {
				blank.push_back(location(i, j));
			}
		}
	}

	//rand() % blank_size returns a random number from 0 to size-1. So this 
	//returns a random coordinate from within the vector.
	if (blank.size() > 0) {
		return blank[rand() % blank.size()];
	}
	else {
		return _location; //return the current location
	}
}

/*Finds all the spaces around the Creature filled with Creatures of type "find"*/
Vector<location> Creature::find_this_creature(Creature* pos[][G_SIZE], const type find) {
	Vector<location> type_locs;
	for (int i = (_location._i - 1); i <= _location._i + 1; i++) {
		for (int j = (_location._j - 1); j <= (_location._j + 1); j++) {
			//will always check for nullptr FIRST, so we don't have to worry about accidental
			//dereferences. typeOf() returns the type of the creature.
			if (pos[i][j] != nullptr && pos[i][j]->typeOf() == find) {
				type_locs.push_back(location(i, j));
			}
		}
	}
	return type_locs;
}

/*Finds all the spaces around the Creature filled which are not of type "find"*/
Vector<location> Creature::find_not_this_creature(Creature* pos[][G_SIZE], const type find) {
	Vector<location> not_locs;
	for (int i = (_location._i - 1); i <= _location._i + 1; i++) {
		for (int j = (_location._j - 1); j <= (_location._j + 1); j++) {
			//will always check for nullptr FIRST, so we don't have to worry about accidental
			//dereferences. typeOf() returns the type of the creature.
			if (pos[i][j] != nullptr && pos[i][j]->typeOf() != find) {
				not_locs.push_back(location(i, j));
			}
		}
	}
	return not_locs;
}

/*Creates a new creature in a location passed to you*/
bool Creature::breed(Creature* pos[][G_SIZE], const location coords) {
	//If the coordinates are within the grid and the position isn't occupied
	if (coords._i >= 0 && coords._j >= 0 && coords._i < G_SIZE && coords._j < G_SIZE && pos[coords._i][coords._j] == nullptr) {
		pos[coords._i][coords._j] = new Creature(coords._i, coords._j);
		return true;
	}else{
		return false;
	}
}


/*Deletes the Creature from the grid and deletes itself to prevent memory leaks*/
void Creature::kill(Creature* pos[][G_SIZE]) {
	pos[_location._i][_location._j] = nullptr;
	delete this;
}

void Creature::draw(sf::RenderWindow& window, location loc) {
	//Make a vector which contains the location the window
	int vectorY = loc._i * (CELL_SIZE + 1);
	int vectorX = loc._j *(CELL_SIZE + 1);

	//Make a circle with a radius 1/2 the cell size
	sf::CircleShape circle(CELL_SIZE/2);

	circle.setFillColor(sf::Color(252, 96, 96, 500));
	//Move to the passed location
	circle.move(vectorX, vectorY);

	window.draw(circle);
}

ostream& operator <<(ostream& outs, const Creature &c) {
	outs << "x";
	return outs;
}

istream& operator >>(istream& ins, Creature &c) {
	unsigned int x;
	unsigned int y;

	do {
		ins >> x;
		cout << ",";
		ins >> y;

		if (x >= G_SIZE || x < 0) {
			cout << endl << "Invalid x! Renter x & y: ";
		}
		if (y >= G_SIZE || x < 0) {
			cout << endl << "Invalid y! Renter x & y: ";
		}

	} while (x >= G_SIZE || y >= G_SIZE);

	c._location._i = x;
	c._location._j = y;

	return ins;
}