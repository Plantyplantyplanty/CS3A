#include "Function.h"

/*You're supposed to do this if-else chain twice. But instead I bound the function. */
Function::Function(string op) :Operator(op) {
	using namespace std::placeholders;

	//I looked how to do this binding. I feel so cool doing this. Please don't kill me.
	if (op == "sin") {
		_func = std::bind((double(*)(double)) & std::sin, _1);
		args = 1;
	}
	else if (op == "cos") {
		_func = std::bind((double(*)(double)) & std::cos, _1);
		args = 1;
	}
	else if (op == "ln") {
		_func = std::bind((double(*)(double)) & std::log, _1);
		args = 1;
	}
	else if (op == "tan") {
		_func = std::bind((double(*)(double)) & std::tan, _1);
		args = 1;
	}
	else if (op == "log") {
	    _func2 = &Function::log_w_base;
		args = 2;
	}
	else if (op == "e^") {
		_func = std::bind((double(*)(double)) & std::exp, _1);
		args = 1;
	}
	else if (op == "Gamma") {
		_func = std::bind((double(*)(double)) & std::tgamma, _1);
		args = 1;
	}
	else {
		assert(0 && "INVALID FUNCTION");
	}
};
//Also assigns the precedence and right associativity of the operator

Token_type Function::type() const {
	return FUNC;
}
//Returns the type of the token

double Function::evaluate(double args) {
	return _func(args);
}

double Function::evaluate(double arg1, double arg2) {
	return _func2(this, arg1, arg2);
}

/*double Function::evaluate(double arg1, double arg2) {
	return _func2(arg1, arg2);
}

/*Prints the token*/
ostream& Function::print(ostream& outs) const {
	return Operator::print(outs);
}
ostream& operator <<(ostream& outs, const Function& t) {
	return t.print();
}
ostream& operator <<(ostream& outs, const Function* t) {
	return t->print();
}