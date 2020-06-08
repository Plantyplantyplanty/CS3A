#define _CRTDBG_MAP_ALLOC
#pragma once
#include "Token.h"
class Variable : public Token{

public:
	Variable();
	//Does nothing 

	virtual Token_type type() const;
	//Returns the type of the token

	/*Prints the token*/
	virtual ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream& outs, const Variable& t);
	friend ostream& operator <<(ostream& outs, const Variable* t);
};

