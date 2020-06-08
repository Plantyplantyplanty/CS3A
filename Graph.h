#define _CRTDBG_MAP_ALLOC
#ifndef GRAPH_H
#define GRAPH_H

#include "Plot.h"
#include  "Tokenizer.h"

class Graph {
public:
	Graph(Graph_info* info);
	void draw(sf::RenderWindow& window); //Draws the points in _points
	void update(); //refreshes the collection of points in _points
private:
	Graph_info* _info;
	Vector<sf::Vector2<float>> _points; //The collection of points to draw
	
	sf::RectangleShape frame; //The graph's frame(not implemented)
	sf::CircleShape point;    //The point

	void drawXaxis(sf::RenderWindow& window);
	void drawYaxis(sf::RenderWindow& window);
	void drawGraph(sf::RenderWindow& window);

	Plot p; //what calculates the points in _points
	/*Draws the axis and a rectangle in the middle of the screen. I don't like the distortion
	 from a non-square screen.*/
};

#endif
