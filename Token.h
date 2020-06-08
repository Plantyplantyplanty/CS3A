#define _CRTDBG_MAP_ALLOC
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

/*The type of the token*/
enum Token_type{LPAREN, NUM, OPER, RPAREN, TOKEN, FUNC, VARIABLE};

class Token{

public:
	Token();
	//Does nothing 

	virtual Token_type type() const;
	//Returns the type of the token

	/*Prints the token*/
	virtual ostream& print(ostream& outs = cout) const;
	friend ostream& operator <<(ostream &outs, const Token& t);
	friend ostream& operator <<(ostream& outs, const Token* t);
};

#endif