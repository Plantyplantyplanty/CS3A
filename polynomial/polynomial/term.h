#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <cassert>
using namespace std;

struct Term {
	Term(); //exp =0, coeff = 0;
	Term(double c, unsigned int exp);
	friend Term operator +(const Term& T1, const Term& T2);
	friend Term operator -(const Term& T1, const Term& T2);

	friend ostream& operator <<(ostream& outs, const Term& T);

	friend bool operator ==(const Term& lhs, const Term& rhs);
	friend bool operator !=(const Term& lhs, const Term& rhs);
	friend bool operator >(const Term& lhs, const Term& rhs);
	friend bool operator <(const Term& lhs, const Term& rhs);

	//Doesn't make sense to use this in dividing two polynomials. Did something complicated
	//instead
	friend Term operator / (const Term& lhs, const Term& rhs);

	double _coef;
	unsigned int _exp;
};

#endif
