#define _CRTDBG_MAP_ALLOC
#ifndef NUMBER_H
#define NUMBER_H

#include "Token.h"
class Number: public Token{
public:
	Number(double num);

	//Token_type is an enum which returns the token type
	Token_type type() const;
	//accessor
	double num() const;

	//Prints the number
	ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream& outs, const Number& t);
	friend ostream& operator <<(ostream& outs, const Number* t);
private:
	double _num;
};

#endif