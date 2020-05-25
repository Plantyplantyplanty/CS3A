#include "Grid.h"

/*Initializes all _grid cells to nullptr*/
Grid::Grid() {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			_grid[i][j] = nullptr;
		}
	}
}

/*Copy constructor*/
Grid::Grid(const Grid& og) {
	copyGrid(og);
}

/*Assignment operator*/
Grid& Grid::operator =(const Grid& og) {
	if (&og != this) {
		delete_grid();
		//Copies the grid, creating a new set of distinct dynamic variables
		copyGrid(og);
	}
	return *this;
}

/*Copies the _grid*/
void Grid::copyGrid(const Grid& og){
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			//if the og's cell points to null, assign null to this cell
			if (og._grid[i][j] == nullptr) {
				_grid[i][j] = nullptr;
			}
			else {
				//Create the appropriate type of creature in the cell
				//Should maybe be a seperate function?
				switch (og._grid[i][j]->typeOf()) {
				case(WALL_CREATURE):
					_grid[i][j] = new Wall_Creature(i, j);
					break;
				case(PREY):
					_grid[i][j] = new Prey(i, j);
					break;
				case(PREDATOR):
					_grid[i][j] = new Predator(i, j);
					break;
				default:
					assert(1);
				};
			}
		}
	}
}

/*Populates the grid with Creatures*/
void Grid::fill_grid(int num_prey, int num_preds){
	//Fill in all of the wall creatures
	fill_wall_creatures();

	/*Should these be seperate functions? Probably*/
	//Fill in the prey
	for (int i = 0; i < num_prey; i++) {
		location empty = get_empty_space();
		Prey * p = new Prey(empty._i, empty._j);
		_grid[empty._i][empty._j] = p;
	}

	//Fill in the predators
	for (int i = 0; i < num_preds; i++) {
		location empty = get_empty_space();
		Predator* h = new Predator(empty._i, empty._j);
		_grid[empty._i][empty._j] = h;
	}
}

/*Gets an empty space in the grid*/
location Grid::get_empty_space() {
	unsigned int x = 0;
	unsigned int y = 0;

	do {
		x = rand() % (G_SIZE - 1);
		y = rand() % (G_SIZE - 1);
	} while (_grid[x][y] != nullptr);
	return location(x, y);
}

/*Puts the Wall Creatures around the borders*/
void Grid::fill_wall_creatures(){
	for (int i = 0; i < G_SIZE; i++) {
		_grid[0][i] = new Wall_Creature(0, i);
		_grid[i][0] = new Wall_Creature(i, 0);
		_grid[G_SIZE - 1][i] = new Wall_Creature(G_SIZE - 1, i);
		_grid[i][G_SIZE - 1] = new Wall_Creature(i, G_SIZE - 1);
	}
}

/*Moves all of the creatures*/
void Grid::Step(){
	//Resets all of the creature's moved functions
	reset_moved();

	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if ((_grid[i][j]) != nullptr && (_grid[i][j]->get_moved() == false)) {
				(_grid[i][j])->move(_grid);
			}
		}
	}
}

/*Resets all of the creature's moved booleans to show that they have not been moved
this turn*/
void Grid::reset_moved() {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if ((_grid[i][j]) != nullptr) {
				(_grid[i][j])->reset_moved();
			}
		}
	}
}

/*Calls all of the Creature's "breed" functions*/
void Grid::Breed() {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if ((_grid[i][j]) != nullptr) {
				// Calls the breed function for each creature, passing it the grid and a set of
			    //random blank coordinates
				(_grid[i][j])->breed(_grid, _grid[i][j]->find_blank(_grid));
			}
		}
	}
}

/*Calls all of the Creature's "kill" functions. In practicality, this is only useful for 
starving off Predators*/
void Grid::Kill() {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if ((_grid[i][j]) != nullptr) {	
					// Calls the breed function for each creature, passing it the grid and a set of
					//random blank coordinates
					(_grid[i][j])->kill(_grid);	
			}
		}
	}
}

void Grid::Draw(sf::RenderWindow& window) {
	//Draws the underlying grid
	for (int row = 0; row < G_SIZE; row++) {
		for (int col = 0; col < G_SIZE; col++) {
			int vectorY = row * (CELL_SIZE + 1);
			int vectorX = col * (CELL_SIZE + 1);

			sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			rectangle.setOutlineColor(sf::Color::White);
			rectangle.setFillColor(sf::Color::Black);
			rectangle.setOutlineThickness(1.5);
			rectangle.move(vectorX, vectorY);

			window.draw(rectangle);
		}
	}

	//Draws the creatures
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if ((_grid[i][j]) != nullptr) {
				// Calls the draw function for each creature
				(_grid[i][j])->draw(window, location(i, j));
			}
		}
	}
}

/*ostream for the grid. I hate this.*/
ostream& operator <<(ostream& outs, Grid g) {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if (g._grid[i][j] == nullptr) {
				outs << ".";
			}
			else {
				switch (g._grid[i][j]->typeOf()) {
				case(WALL_CREATURE):
					cout << *(static_cast<Wall_Creature*>(g._grid[i][j]));
					break;
				case(PREY):
					cout << *(static_cast<Prey*>(g._grid[i][j]));
					break;
				case(PREDATOR):
					cout << *(static_cast<Predator*>(g._grid[i][j]));
					break;
				default:
					assert(1);
				};
			}
		}
		outs << endl;
    }	
    return outs;
}
	
void Grid::delete_grid() {
	for (int i = 0; i < G_SIZE; i++) {
		for (int j = 0; j < G_SIZE; j++) {
			if (_grid[i][j] != nullptr) {
				delete _grid[i][j];
			}
		}
	}
}

Grid::~Grid() {
	delete_grid();
}