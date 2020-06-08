#include "translate_coords.h"

translate_coords::translate_coords(Graph_info* info){
	_info = info;
}

sf::Vector2<float> translate_coords::getTranslation(sf::Vector2<float> point) {
	/*_info->window_dimensions = sf::Vector2<float>(WORK_PANEL, SCREEN_HEIGHT);
    _info->domain = sf::Vector2<float>(-X_MAX,X_MAX);
    _info->origin = sf::Vector2<float>(SCREEN_HEIGHT / 2, WORK_PANEL / 2);
    _info->scale = sf::Vector2<float>(SCREEN_HEIGHT / (2 * X_MAX + 1), SCREEN_HEIGHT / (2 * Y_MAX + 1));*/
	 point.x = _info->origin.y + point.x * _info->scale.x;
	 point.y = _info->origin.x + -point.y * _info->scale.y;
	//Is a + x*shift
			//The +1 shifts the last point up a tiny bit so that you can see it
	//point.x = ((WORK_PANEL / 2) + point.x * WORK_PANEL / (2 * X_MAX));
	//point.y = ((SCREEN_HEIGHT / 2) + -point.y * SCREEN_HEIGHT / (2 * X_MAX));
	
	return point;
}

sf::Vector2<float> translate_coords::operator()(sf::Vector2<float> point) {
	return getTranslation(point);
}