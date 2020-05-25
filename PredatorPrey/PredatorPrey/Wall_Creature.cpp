#include "Wall_Creature.h"

//Easiest class ever. These guys just sit there.
Wall_Creature::Wall_Creature(unsigned int x, unsigned int y): Creature(x, y) {}

bool Wall_Creature::move(Creature* pos[][G_SIZE]) { return false; }
bool Wall_Creature::breed(Creature* pos[][G_SIZE], location coords) { return false; }
void Wall_Creature::kill(Creature* pos[][G_SIZE]){/*immortal*/}

void Wall_Creature::draw(sf::RenderWindow& window, location loc) {
	int vectorY = loc._i * (CELL_SIZE + 1);
	int vectorX = loc._j * (CELL_SIZE + 1);

	sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	rect.setFillColor(sf::Color(44, 130, 193, 200));
	rect.setOutlineThickness(1.5);
	rect.setOutlineColor(sf::Color::White);
	rect.move(vectorX, vectorY);

	window.draw(rect);
}

ostream& operator <<(ostream& outs, Wall_Creature c) {
	outs << "W";
	return outs;
}