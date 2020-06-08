#include "Plot.h"

Plot::Plot(Graph_info *info) {
	_info = info;
}

Vector<sf::Vector2<float>> Plot::oper() {
	//Run our equation through the tokenizer
	Tokenizer tokenizer;
	 Queue<Token*> t = tokenizer(_info->equation);
	 Vector<sf::Vector2<float>> coords;
	 if (t.size() > 0) {
		 /*
		 Kept for debug purposes
		Token* a = new Operator("+");
		Token* s = new Operator("-");
		Token* e = new Operator("^");
		Token* m = new Operator("*");
		Token* d = new Operator("/");

		LeftParen* l = new LeftParen();
		RightParen* r = new RightParen();

		t.push(new Function("ln"));
		t.push(l);
		t.push(new Variable());
		t.push(r);*/

		//Vector<sf::Vector2<float>> coords; // Vector of coordinates to return

		//Equation goes through shunting yard
		 shunting_yard sy(t);
		 _postfix = sy.postfix();

		 //run each point through RPN, translate it and the matching x, and then add it to the 
		 //vector of coordinates
		 RPN rhs;
		 translate_coords tc(_info);

		 _info->scale.x = _info->reset_x_scale();
		 _info->scale.y = _info->reset_y_scale();

		 /*For all of the steps, get a y from rpn and push back the coordinates*/
		 double step = (_info->domain.y - _info->domain.x) / _info->points;
		 for (double i = _info->domain.x; i <= _info->domain.y; i += step) {
			 double y = rhs(_postfix, i);
			 coords.push_back(tc(sf::Vector2<float>(i, y)));
		 }
	 }

	 while (t.size() > 0) {
		 delete t.pop();
	 }

	return coords;
}

Vector<sf::Vector2<float>> Plot::operator()() {
	return oper();
}

