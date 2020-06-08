#define _CRTDBG_MAP_ALLOC
#ifndef SHUNTING_Y_H
#define SHUNTING_Y_H

//REMOVE INTERNALS, DUPLICATE ALL OF HIS TESTS 

#include "Queue.h"
#include "Token.h"
#include "Stack.h"
#include "Number.h"
#include "Operator.h"
#include "RightParen.h"
#include "LeftParen.h"
#include "Variable.h"
#include "Function.h"

class shunting_yard{
public:
	shunting_yard(const Queue<Token*>& infix); 
	//hands infix over to get_postfix() to be converted to postfix notation

	Queue<Token*> postfix(); 
	//returns the postfix expression

	friend ostream& operator <<(ostream& outs, const shunting_yard& t);

private:
	Queue<Token*> _tokens; //an infix notation queue

	void get_postfix(Queue<Token*> infix); 	//LOGICALLY the same thing as const& then making a copy
    //creates the postfix queue
	void postfix_op(Stack<Token*> &ops, Queue<Token*>& postfix, Token *t);
	//deals with the operator case
};

#endif