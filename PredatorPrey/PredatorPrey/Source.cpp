/*
 * Author: Marisa Persaud
 * Project: Predator-Prey
 * Purpose: Create a semi-sustainable ecosystem with predators, prey, and walls
 * Notes: This was fun! I would do more of this. 
 *
 

#include "Grid.h"

int main() {
	Grid g;
	g.fill_grid(100, 5);
	cout << g << endl;
	for (int i = 0; i < 305; i++) {
	  cout << "Generation " << i << endl;
	  g.Step();
	  g.Breed();
	  g.Kill();
	  cout << g << endl;
	}
	return 0;
}*/