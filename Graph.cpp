#include "Graph.h"
#include "constants.h"

Graph::Graph(Graph_info* info):p(info){
	_info = info;
	
	/*IF WE EVER WANT A FRAME
	sf::Vector2<float> screen(FRAME_WIDTH, FRAME_HEIGHT);
	frame.setSize(screen);
	frame.setFillColor(sf::Color::Transparent);
	frame.setPosition(FRAME_OFFSET / 2, (FRAME_OFFSET / 2));
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(2);*/

	point.setRadius(2);
	point.setFillColor(sf::Color::White);
}

void Graph::draw(sf::RenderWindow& window) {

	drawXaxis(window);
	drawYaxis(window);
	drawGraph(window);
	window.draw(frame);
}

/*Draws the graph*/
void Graph::drawGraph(sf::RenderWindow& window) {
	//Creates a point

	//Actually draws the function
	while (_points.size() > 0) {
		point.setPosition(_points.pop_back());
		window.draw(point);
	}
}

/*Draws X axis and grid*/
void Graph::drawXaxis(sf::RenderWindow& window){
	//Draws the axis
	sf::Vector2<float> screen(1, _info->window_dimensions.y);
	sf::RectangleShape y_axis(screen);

	y_axis.setPosition(_info->origin.y, 1);
	window.draw(y_axis);

	//Draws the grid lines
	y_axis.setFillColor(sf::Color(255, 255, 255, 70));
	for (double i = 0; i < (_info->window_dimensions.x / _info->scale.x); i++) {
		y_axis.setPosition(i * _info->scale.x, 1);
		window.draw(y_axis);
	}
}

/*Draws Y axis and grid*/
void Graph::drawYaxis(sf::RenderWindow& window){
	//Draws the axis
	sf::Vector2<float> screen2(_info->window_dimensions.x, 1);
	sf::RectangleShape x_axis(screen2);

	x_axis.setPosition(1, _info->origin.x);
	window.draw(x_axis);
	 
	//Draws the grid lines
	x_axis.setFillColor(sf::Color(255, 255, 255, 70));
	for (double i = 0; i < (_info->window_dimensions.y / _info->scale.y); i++) {
		x_axis.setPosition(1, i * _info->scale.y);
		window.draw(x_axis);
	}
}

void Graph::update() {
	_points = p();
}


