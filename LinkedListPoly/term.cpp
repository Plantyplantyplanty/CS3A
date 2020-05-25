#include "term.h"
#include <iomanip>

Term::Term(double c, unsigned int e) :_coef(c), _exp(e) {}

Term::Term() : _coef(0), _exp(0) {}

Term operator +(const Term& T1, const Term& T2) {
	assert(T1._exp == T2._exp);
	//Add the coefficents, keep the exponent
	return Term(T1._coef + T2._coef, T1._exp);
}

Term operator -(const Term& T1, const Term& T2) {
	assert(T1._exp == T2._exp);
	//Subtract the coefficents, keep the exponent
	return Term(T1._coef - T2._coef, T1._exp);
}

Term Term::operator -() const{
	//Make the coefficent negative
	return Term(_coef * -1, _exp);
}

ostream& operator <<(ostream& outs, const Term& T) {
	if (T._exp != 0) {
		if (T._coef != 1) {
			outs << setprecision(1) << fixed << T._coef;
		}
		outs << "x";
		if (T._exp != 1) {
			outs << "^" << T._exp;
		}
	}
	else {
		outs << setprecision(1) << fixed << T._coef;
	}
	return outs;
}

bool operator ==(const Term& lhs, const Term& rhs) {
	if (lhs._exp == rhs._exp) {
		return true;
	}
	else
		return false;
}

bool operator !=(const Term& lhs, const Term& rhs) {
	if (lhs._exp !=  rhs._exp){
		return false;
	}
	else
		return true;
}

bool operator >(const Term& lhs, const Term& rhs) {
	if (lhs._exp > rhs._exp) {
		return true;
	}
	else
		return false;

}

bool operator <(const Term& lhs, const Term& rhs) {
	if (lhs._exp < rhs._exp) {
		return true;
	}
	else
		return false;
}

bool operator >=(const Term& lhs, const Term& rhs){
	if (lhs._exp >= rhs._exp) {
		return true;
	}
	else
		return false;
}

bool operator <=(const Term& lhs, const Term& rhs){
	if(lhs._exp <= rhs._exp) {
		return true;
	}
	else
		return false;
}

Term operator * (const Term& lhs, const Term& rhs) {
	//Multiply coefficents, add exponents
	return Term(lhs._coef * rhs._coef, lhs._exp + rhs._exp);
}

Term operator / (const Term& lhs, const Term& rhs) {
	Term to_return;
	assert(rhs._coef != 0); //Can't divide by 0

	//Otherwise return 0^0 from default constructor
	if (lhs._exp >= rhs._exp) { 
		//Divide coefficents, subtract exponents
		return Term(lhs._coef / rhs._coef, lhs._exp - rhs._exp);
	}
	return to_return;
}