#include "Predator.h"

/*Assigns the Predator's coordinates. Its time to breed and time to starve are initialized to 
one*/
Predator::Predator(unsigned int x, unsigned int y):Creature(x, y), _time_to_breed(1), _starve(1)
{}

bool Predator::move(Creature* pos[][G_SIZE]) {
	Vector<location> to_eat = Creature::find_this_creature(pos, PREY);
	if (to_eat.size() > 0) {
		//selects a random location in "eaten" from 0 to size
		location eaten = to_eat[rand() % to_eat.size()];
		//Calls the kill function on the prey
		static_cast<Prey*>(pos[eaten._i][eaten._j])->die(pos);
		//Replaces it with this object
		Creature::move_to(pos, eaten);

		//Resets starved
		_starve = 1;
		return true;
	}
	else {
		//Move in a random direction, poor hungry thing you
		_starve++; 
		return Creature::move(pos);
	}
}

/*Breeds the Predator*/
bool Predator::breed(Creature* pos[][G_SIZE], location coords) {
	bool success = false;;
	if (_time_to_breed >= TIME_TO_BREED) {
		//If the coordinates are within the grid and the position isn't occupied
		if (coords._i >= 0 && coords._j >= 0 && coords._i < G_SIZE && coords._j < G_SIZE && pos[coords._i][coords._j] == nullptr) {
			pos[coords._i][coords._j] = new Predator(coords._i, coords._j);
			success = true;
		}
		_time_to_breed = 1; //Resets the time to breed
	}
	else {
		_time_to_breed++; 
	}
	return success;
}

/*If the Predator hasn't eaten in too long, it dies*/
void Predator::kill(Creature* pos[][G_SIZE]) {
	if (_starve >= STARVATION) {
		//Reminder: sets space in grid to null, deletes this object
		Creature::kill(pos);
	}
}

void Predator::draw(sf::RenderWindow& window, location loc){
	sf::CircleShape diamond(CELL_SIZE / 2, 4); //Creates a diamond

	int vectorY = loc._i * (CELL_SIZE + 1);
	int vectorX = loc._j * (CELL_SIZE + 1);

	diamond.setFillColor(sf::Color(127, 102, 249, 500));
	diamond.move(vectorX, vectorY);

	window.draw(diamond);
}

ostream& operator <<(ostream& outs, const Predator& c) {
	outs << "X";
	return outs;
}

