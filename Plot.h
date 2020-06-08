#define _CRTDBG_MAP_ALLOC
#ifndef PLOT_H
#define PLOT_H

#include "shunting_yard.h"
#include "translate_coords.h"
#include "Tokenizer.h"

class Plot{
public:
	Plot(Graph_info* _info);
	Vector<sf::Vector2<float>> oper();
	Vector<sf::Vector2<float>> operator()();
	//Does all work
private:
	Queue<Token*> _postfix;
	Graph_info* _info;
};

#endif