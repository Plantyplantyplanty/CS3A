#include "Operator.h"

/*Sets the operator, its precedence, and its right associativity*/
Operator::Operator(string op) {
	if (op == "^") {
		_prec = THIRD;
		right_as = true;
	}
	else if (op == "/") {
		_prec = SEC;
		right_as = false;
	}
	else if (op == "*") {
		_prec = SEC;
		right_as = false;
	}
	else if (op == "+") {
		_prec = FIRST;
		right_as = false;
	}
	else if (op == "-") {
		_prec = FIRST;
		right_as = false;
	}
	else {
		_prec = FOURTH;
	}
	_operator = op;
}

/*Returns the type of Token this is*/
Token_type Operator::type() const{
     return OPER;
}

/*Returns the precedence of this operator. precedence is an enum*/
precedence Operator::prec() const{
	return _prec;
}

//accessor
string Operator::op() const{
	return _operator;
}

/*Prints the token*/

ostream& Operator::print(ostream& outs) const{
	outs << _operator;
	return outs;
}

ostream& operator <<(ostream& outs, const Operator &t) {
	return t.print(outs);
}

ostream& operator <<(ostream& outs, const Operator* t) {
	return t->print(outs);
}