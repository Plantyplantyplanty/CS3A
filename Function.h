#define _CRTDBG_MAP_ALLOC
#ifndef FUNCTION_F
#define FUNCTION_F

#include <functional>
#include <cstdarg>

#include "Operator.h"


class Function :public Operator{
public:
	Function(string op);
	//Also assigns the precedence and right associativity of the operator
	unsigned int num_args() const { return args; }
	double evaluate(double args);
	double evaluate(double arg1, double arg2);
	//evaluates the function

	Token_type type() const;
	//Returns the type of the token

	double log_w_base(double a, double b) {
		return log(b) / log(a);
	}

	/*Prints the token*/
	ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream& outs, const Function& t);
	friend ostream& operator <<(ostream& outs, const Function* t);
private:
	std::function<double(double)> _func; //function binder
	std::function<double(Function*, double, double)> _func2; //function binder
	unsigned int args; //number of arguments to take in
};

#endif

