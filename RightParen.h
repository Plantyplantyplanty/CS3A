#define _CRTDBG_MAP_ALLOC
#pragma once

#include "Token.h"
class RightParen: public Token{
public:
	RightParen();
	//Does nothing 

	Token_type type() const;
	//Returns the type of the token

	/*Prints the token*/
	ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream& outs, const RightParen& t);
	friend ostream& operator <<(ostream& outs, const RightParen* t);
};

