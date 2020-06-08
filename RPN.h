#define _CRTDBG_MAP_ALLOC
#ifndef RPN_H
#define RPN_H

#include "shunting_yard.h"
#include <math.h>
class RPN{
public:
	RPN();
	double getRPN(Queue<Token*> infix, double n);
	double operator()(Queue<Token*> infix, double n);
private:
	void operator_case(Operator* o, Stack<Number*>& nums);
};

#endif
