#define _CRTDBG_MAP_ALLOC
#ifndef TRANS_COORDS_H
#define TRANS_COORDS_H

#include <vector>
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "RPN.h"
#include "constants.h"
#include "Graph_info.h"

class translate_coords {
public:
	translate_coords(Graph_info* info);
	//Gets translated set of coordinates given the x and y queues
	sf::Vector2<float> getTranslation(sf::Vector2<float> point);
	sf::Vector2<float> operator()(sf::Vector2<float> point);
private:
	Graph_info* _info;
};

#endif