#include "Token.h"

//Empty
Token::Token(){}

//Returns the type of the token
Token_type Token::type() const{
	return TOKEN;
}

//Prints the token
ostream& Token::print(ostream& outs) const{
	outs << "X";
	return outs;
}

ostream& operator <<(ostream& outs, const Token& t) {
	return t.print(outs);
}

ostream& operator <<(ostream& outs, const Token* t) {
	return t->print(outs);
}