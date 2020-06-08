#include "RPN.h"

RPN::RPN() {}

double RPN::operator()(Queue<Token*> infix, double n) {
	return getRPN(infix, n);
}

/*Main computational function*/
double RPN::getRPN(Queue<Token*> infix, double n) {
	Stack<Number*> nums;
	while (infix.size() > 0) {
		Token* t = infix.pop();
		Token_type type = t->type();

		switch (type) {
		case(NUM): 
			nums.push(new Number(*(static_cast<Number*>(t))));
			break;
		case(VARIABLE):
			nums.push(new Number(n));
			break;
		case(OPER):
			operator_case(static_cast<Operator*>(t), nums);
			break;
		case(FUNC):
			double a = 0;
			if (static_cast<Function*>(t)->num_args() == 1) {
				Number* to_eval = nums.pop();
				a = static_cast<Function*>(t)->evaluate(to_eval->num());
				delete to_eval;
			}
			else if (static_cast<Function*>(t)->num_args() == 2){
				Number* to_eval1 = nums.pop();
				Number* to_eval2 = nums.pop();

				a = static_cast<Function*>(t)->evaluate(to_eval1->num(), to_eval2->num());

				delete to_eval1;
				delete to_eval2;
			}
			nums.push(new Number(a));
			break;
		};
	}

	Number* answer = nums.pop();
	double ans = answer->num();
	delete answer;
	return ans;
}

void RPN::operator_case(Operator* o, Stack<Number*>& nums) {
	string op = o->op();

	//Pop the Numbers to evaluate
	Number * to_eval1 = nums.pop();
	Number * to_eval2 = nums.pop();

	//Get their numbers
	double a = to_eval1->num();
	double b = to_eval2->num();

	delete to_eval1;
	delete to_eval2;

	if (op == "^") {
		//cout << a << "^" << b << " = " << pow(b, a) << endl;
		nums.push(new Number(pow(b,a)));
	}
	else if (op == "/") {
		//cout << b << " / " << a << " = " << b/a << endl;
		//Check for 0
		if (abs(a) > -DBL_MAX) {
			nums.push(new Number(b / a));
		}
		else {
			nums.push(new Number(0));
		}
	}
	else if (op == "*") {
		//cout << b << " * " << a << " = " << b*a << endl;
		nums.push(new Number(b * a));
	}
	else if (op == "+") {
		//cout << a << " + " << b << " = " << b + a << endl;
		nums.push(new Number(b + a));
	}
	else if (op == "-") {
		//cout << b << " - " << a << " = " << b - a << endl;
		nums.push(new Number(b - a));
	}
	else {
		assert(0 && "INVALID OPERATOR");
	}
}
