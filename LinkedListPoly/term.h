#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <cassert>
using namespace std;

struct Term {
	Term(); //exp =0, coeff = 0;
	Term(double c, unsigned int exp);

	//Arithmetic Operators
	friend Term operator +(const Term& T1, const Term& T2);
	friend Term operator -(const Term& T1, const Term& T2);
	friend Term operator / (const Term& lhs, const Term& rhs);
	friend Term operator * (const Term& lhs, const Term& rhs);
	Term operator -() const;

	friend ostream& operator <<(ostream& outs, const Term& T);

	//Boolean operators ONLY COMPARE EXPONENTS
	friend bool operator ==(const Term& lhs, const Term& rhs);
	friend bool operator !=(const Term& lhs, const Term& rhs);
	friend bool operator >(const Term& lhs, const Term& rhs);
	friend bool operator <(const Term& lhs, const Term& rhs);
	friend bool operator >=(const Term& lhs, const Term& rhs);
	friend bool operator <=(const Term& lhs, const Term& rhs);

	double _coef; //Holds the coefficent
	unsigned int _exp; //Holds the exponent
};

#endif