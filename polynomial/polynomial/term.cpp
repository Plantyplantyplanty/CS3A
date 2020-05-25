#include "term.h"
#include <iomanip>

Term::Term(double c, unsigned int e):_coef(c), _exp(e) {
}

Term::Term():_coef(0), _exp(0) {

}

Term operator +(const Term& T1, const Term& T2) {
	assert(T1._exp == T2._exp);
	return Term(T1._coef + T2._coef, T1._exp);
}

Term operator -(const Term& T1, const Term& T2) {
	assert(T1._exp == T2._exp);
	return Term(T1._coef - T2._coef, T1._exp);
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
		if (abs(lhs._coef - rhs._coef) < .001) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool operator !=(const Term& lhs, const Term& rhs) {
	if (lhs == rhs) {
		return false;
	}
	else
		return true;
}

bool operator >(const Term& lhs, const Term& rhs) {
	if (lhs._exp > rhs._exp) {
		return true;
	}
	else if (lhs._exp == rhs._exp) {
		if (lhs._coef > rhs._coef) {
			return true;
		}
		else
			return false;
	}
	else
		return false;

}

bool operator <(const Term& lhs, const Term& rhs) {
	if (lhs > rhs) {
		return false;
	}
	else if (lhs == rhs) {
		return false;
	}
	else
		return true;
}

Term operator / (const Term& lhs, const Term& rhs) {
	Term to_return;
	assert(rhs._coef != 0);
	if (lhs._exp > rhs._exp) {
		return Term (lhs._coef/rhs._coef, lhs._exp - rhs._exp);
	}
	else if (lhs._exp == rhs._exp) {
		return Term(lhs._coef / rhs._coef, lhs._exp);
	}
	return to_return;
}