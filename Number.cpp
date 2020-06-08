#include "Number.h"

//Sets the private _num variable to whatever is passed to the constructor
Number::Number(double num):_num(num) {}

/*Returns the type of Token this is. Token_type is an enum.*/
Token_type Number::type() const{
	return NUM;
}

//Accessor
double Number::num() const{
	return _num;
}

/*Prints the number*/
ostream& Number::print(ostream& outs) const{
	outs << _num;
	return outs;
}

ostream& operator <<(ostream& outs, const Number& t) {
	return t.print(outs);
}

ostream& operator <<(ostream& outs, const Number* t) {
	return t->print(outs);
}