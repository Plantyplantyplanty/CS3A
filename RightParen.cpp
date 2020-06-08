#include "RightParen.h"

RightParen::RightParen(){}
//Does nothing 

/*Returns what type of Token this is*/
Token_type RightParen::type() const{ 
	return RPAREN;
} 

/*Prints the token*/
ostream& RightParen::print(ostream& outs) const{
	outs << ")";
	return outs;
}

ostream& operator <<(ostream& outs, const RightParen& t) {
	return t.print(outs);
}
ostream& operator <<(ostream& outs, const RightParen* t) {
	return t->print(outs);
}