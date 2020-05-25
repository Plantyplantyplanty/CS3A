#include "Prey.h"

//Initializes the time to increment to breed to 1
Prey::Prey(unsigned int x, unsigned int y): Creature(x, y), _time(1){}

/*Moves the Prey*/
bool Prey::move(Creature* pos[][G_SIZE]) {
	//Reminder: sets the original position to null and passed location coordinates to "this"
	return Creature::move(pos);
}

/*Breeds this creature*/
bool Prey::breed(Creature* pos[][G_SIZE], location coords) {
	bool success = false;;
	if (_time >= TIME_TO_BREED) {
		//If the coordinates are within the grid and the position isn't occupied
		if (coords._i >= 0 && coords._j >= 0 && coords._i < G_SIZE && coords._j < G_SIZE && pos[coords._i][coords._j] == nullptr) {
			pos[coords._i][coords._j] = new Prey(coords._i, coords._j);
			success = true;
		}
		_time = 1; //reset the time to breed
	}
	else {
		_time++;
	}
	return success;
}

//We don't want to call this function when we are iterating through in Grid's kill. These guys
//only get eaten, but are otherwise immortal
void Prey::kill(Creature* pos[][G_SIZE]) {
	//does nothing
}

//Called when a Prey is predated
void Prey::die(Creature* pos[][G_SIZE]) {
	Creature::kill(pos);
}

void Prey::draw(sf::RenderWindow& window, location loc) {
	Creature::draw(window, loc);
}

ostream& operator <<(ostream& outs, const Prey& c) {
	outs << "o";
	return outs;
}
