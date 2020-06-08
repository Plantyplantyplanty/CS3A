#include "shunting_yard.h"

shunting_yard::shunting_yard(const Queue<Token*>& infix) {
	get_postfix(infix);
}

void shunting_yard::get_postfix(Queue<Token*> infix) {
	Queue<Token*> postfix; //the return queue. Will be set as _tokens.
	Stack<Token*> ops; //Stack of operators

	//For all the tokens in _tokens///
	while (infix.size() > 0) {
		Token* t = infix.pop();
		Token_type type = t->type(); //the type of the token

		switch (type) {
			//if the token is a number
			case(NUM):
			case(VARIABLE):
				postfix.push(t); //push into postfix queue
				break;
			//if the token is a left parenthesis
			case(LPAREN):
				ops.push(t); //push into the operator stack
				break;
			//if the token is an operator
			case(OPER):
			case(FUNC):
				postfix_op(ops, postfix, t); //do this function
				break;
			//if the token is a right parenthesis
			case(RPAREN):
				//Pop/push until you reach a left parenthesis
				while (ops.size() > 0 && (*ops.begin())->type() != LPAREN) {
					postfix.push(ops.pop());
				}
				//Pop the matching right parenthesis
				ops.pop();
				break;
			default:
				assert(0 || "UNKNOWN ITEM");
			}
		}


	//Now we push what remains in the stack into the output queue
	while (ops.size() > 0) {
		postfix.push(ops.pop());
	}
	_tokens = postfix;
}

void shunting_yard::postfix_op(Stack<Token*>& ops, Queue<Token*>& postfix, Token* t) {
	//if the operator stack is empty or the beginning is a left parenthesis
	if (ops.size() == 0 || ((*ops.begin())->type()) == LPAREN) { 
		ops.push(t); //push onto the operator stack
	}
	else {
		//if it's not empty, we have to compare precedence to the top of the stack
		precedence new_op = (static_cast<Operator*>(t)->prec());

		//While the 1.) Stack isn't empty and 2.) the precedence of the operator is less
		//than the precedence of the top of the stack
		while ((ops.size() > 0) && ((*ops.begin())->type() != LPAREN) && (new_op < (static_cast<Operator*>(*ops.begin())->prec()))) {
			postfix.push(ops.pop());
		}
		if (static_cast<Operator*>(t)->associativity()) {
			//if it's right associative, push it
			ops.push(t);
		}
		else { //if it's not, get rid of any operators with equal precedence
			while ((ops.size() > 0) && ((*ops.begin())->type() != LPAREN) && (new_op == (static_cast<Operator*>(*ops.begin())->prec()))) {
				postfix.push(ops.pop());
			}
			//finally push the operator
			ops.push(t);
		}

	}
}

Queue<Token*> shunting_yard::postfix() {
	return _tokens;
}

ostream& operator <<(ostream& outs, const shunting_yard& t) {
	Queue<Token*>::Iterator it = t._tokens.begin();
	while (it != t._tokens.end()) {
		outs << *it << " ";
		it++;
	}
	return outs;
}

