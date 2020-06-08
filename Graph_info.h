#define _CRTDBG_MAP_ALLOC
#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H

#include <string>
#include <SFML/Graphics.hpp>
#include "constants.h"

struct Graph_info{
	Graph_info();
	std::string equation; //the equation we're passing around
	sf::Vector2<float> window_dimensions;
	sf::Vector2<float> origin;
	sf::Vector2<float> scale;
	sf::Vector2<float> domain;
	int points; //Number of points
	void reset(); //Resets to the default 
	double reset_x_scale(); //resets the scale
	double reset_y_scale();
};

#endif