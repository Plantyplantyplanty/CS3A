#include "LeftParen.h"

LeftParen::LeftParen(){}

/*Returns the type of Token this is*/
Token_type LeftParen::type() const{
	return LPAREN;
}

/*Prints the token*/
ostream& LeftParen::print(ostream& outs) const{
	outs << "(";
	return outs;
}
ostream& operator <<(ostream& outs, const LeftParen& t) {
	return t.print(outs);
}
ostream& operator <<(ostream& outs, const LeftParen* t) {
	return t->print(outs);
}