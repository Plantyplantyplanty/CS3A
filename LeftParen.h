#define _CRTDBG_MAP_ALLOC
#pragma once

#include "Token.h"

class LeftParen :public Token{
public: 
	LeftParen();

	Token_type type() const;
	//Returns the type of the token

	/*Prints the token*/
	ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream& outs, const LeftParen& t);
	friend ostream& operator <<(ostream& outs, const LeftParen* t);
};

