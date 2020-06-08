#include "Variable.h"

//Empty
Variable::Variable() {}

//Returns the type of the token
Token_type Variable::type() const {
	return VARIABLE;
}

//Prints the token
ostream& Variable::print(ostream& outs) const {
	outs << "x";
	return outs;
}

ostream& operator <<(ostream& outs, const Variable& t) {
	return t.print(outs);
}

ostream& operator <<(ostream& outs, const Variable* t) {
	return t->print(outs);
}