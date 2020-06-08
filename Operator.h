#define _CRTDBG_MAP_ALLOC
#ifndef OPER_H
#define OPER_H

#include "Token.h"
#include <cassert>
#include <string>

//The precedence of the operator
enum precedence{FIRST, SEC, THIRD, FOURTH};

class Operator: public Token{
public:
	Operator(string op); 
	//Also assigns the precedence and right associativity of the operator

	Token_type type() const;
	//Returns the type of the token
	precedence prec() const;
	//Returns an enum giving the precedence of this operator
	string op() const;
	//Returns the operator
	bool associativity() const { return right_as; }
	//Returns the associativity of the operator

	/*Prints the token*/
	ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream &outs, const Operator &t);
	friend ostream& operator <<(ostream& outs, const Operator* t);

private:
	precedence _prec; //the precedence of this object's operator
	string _operator; //the contained operator
	bool right_as; //right associativity of the expression
};

#endif
