#include "Graph_info.h"

Graph_info::Graph_info() {
	reset();
}

/*Resets object to default values*/
void Graph_info::reset() {
	window_dimensions = sf::Vector2<float>(WORK_PANEL, SCREEN_HEIGHT);
	domain = sf::Vector2<float>(-X_MAX, X_MAX);
	origin = sf::Vector2<float>(SCREEN_HEIGHT / 2, WORK_PANEL/ 2);
	scale.x = reset_x_scale();
	scale.y = reset_y_scale();
	points = POINTS;
}

/*Resets the scale with current values*/
double Graph_info::reset_x_scale() {
	return window_dimensions.x / (double(domain.y - domain.x));
}

/*Reset the scale with current values*/
double Graph_info::reset_y_scale() {
	return window_dimensions.y / (double(domain.y - domain.x));
}