#include "polynomial.h"
#include <math.h>

//order is the order of the polynomial. The size of the array is one more than that.
Poly::Poly(double* coefs, int order) {
	//Order of a polynomial is one less than its size
	_coefs = allocate1D<double>(order + 1);

	copy_list(_coefs, coefs, order + 1);
	_order = order;
}

Poly::Poly(const Poly& original) {
	copy_poly(original);
}

Poly::Poly() {
	_coefs = allocate1D<double>(1);
	_order = 0;
	*_coefs = 0;
}


Poly& Poly::operator =(const Poly& rhs) {
	if (&rhs != this){
		delete[] _coefs;
		copy_poly(rhs);
	}
	return *this;
}

/*Copies one poly object into another
-------------------------------------
Preconditions: rhs has been initialized
Postconditions: this poly now has identical values to rhs but in different memory.
*/
void Poly::copy_poly(const Poly& rhs) {
		_order = rhs._order;
		//Order of a polynomial is one less than its size
		_coefs = allocate1D<double>(rhs._order + 1);

		copy_list(_coefs, rhs._coefs, rhs._order + 1);
}

Term Poly::operator[](int order) const {
	assert(order <= _order && order >= 0);

	//get the address at "order". *index_address is now the correct coefficent
	double* index_address = get_coeff(order); /*_coefs + (_order - order)*/
	return Term(*index_address, order);
}

Poly operator +(const Poly& lhs, const Term& t) {
	Poly new_poly(lhs);
	if (t._exp <= lhs._order) {
		//Get the correct coefficent
		double* old_coef = new_poly.get_coeff(t._exp);
		//Add it to the term's coefficent
		*old_coef += t._coef;
	}
	else {
		//Enlarges the polynomial to t._exp size
		new_poly = new_poly.enlarge_poly(t._exp);
		//Sets the first term's coefficent to be the same as T's coefficient
		*new_poly._coefs = t._coef;
	}
	return Poly(new_poly);
}

Poly operator +(const Poly& lhs, const Poly& rhs){
	Poly new_poly(lhs);

	for (int i = 0; i <= rhs._order; i++) {
		new_poly = new_poly + rhs[i];
	}

	new_poly.fix_order();
	return Poly(new_poly);
}

Poly operator -(const Poly& lhs, const Term& t) {
	Poly new_poly(lhs);
	if (t._exp <= lhs._order) {
		//Get the correct coefficent
		double* old_coef = new_poly.get_coeff(t._exp);
		//Add it to the term's coefficent
		*old_coef -= t._coef;
	}
	else {
		//Enlarges the polynomial to t._exp size
		new_poly = new_poly.enlarge_poly(t._exp);
		//First term is equal to t's exponent * -1.
		*new_poly._coefs = t._coef * -1;
	}
	return Poly(new_poly);
}

Poly operator - (const Poly& lhs, const Poly& rhs) {
	Poly new_poly(lhs);
	for (int i = 0; i <= rhs._order; i++) {
		new_poly = new_poly - rhs[i];
	}
    new_poly.fix_order();
	return Poly(new_poly);
}

Poly operator *(const Poly& lhs, const Term& t) {
	Poly new_poly(lhs);

	//Multiply all of the coefficents by t's coefficent
	new_poly.multiply_coefs(t._coef);

	if (*new_poly._coefs == 0) {
		new_poly.fix_order();
	}

	//Create a new array of the new exponent's size
	int new_order = t._exp + lhs._order;

	//Returns a polynomial of new_order degree with new_poly's coefficents
	return Poly(new_poly.enlarge_poly_front(new_order));
}

Poly operator *(const Poly& lhs, const Poly& rhs) {
	Poly new_poly(lhs * rhs[0]);
	for (int i = 1; i <= rhs._order; i++) {
		Poly temp(lhs * rhs[i]);
		new_poly = (temp + new_poly);
	}

	//If the leading term is 0, fix the order
	if (*new_poly._coefs == 0) {
		new_poly.fix_order();
	}

	return Poly(new_poly);
}

/*Multiplies all of Poly's coefficents by coeff
In this library because as a templated function it does not make sense for string, char
*/
Poly Poly::multiply_coefs(double coeff) {
	double* walker = _coefs;
	for (int i = 0; i <= _order; i++) {
		*walker *= coeff;
		walker++;
	}
	if (*_coefs == 0) {
		fix_order();
	}

	return *this;
}

Poly operator /(const Poly& lhs, const Poly& rhs) {
	Poly new_poly;
	Poly to_return;
	if (lhs._order >= rhs._order) {
		to_return = division(lhs, rhs, new_poly);
	}
	return Poly(to_return);
}

Poly operator %(const Poly& lhs, const Poly& rhs) {
	Poly new_poly = lhs;
	if (lhs._order >= rhs._order) {
		division(lhs, rhs, new_poly);
	}
	return Poly(new_poly);
}

/*Enlarges the polynomial with zeros IN THE BACK
-------------------------------------------------
Preconditions:"This polynomial's order is SMALLER THAN OR EQUAL TO "order"*/
Poly Poly::enlarge_poly_front(int order) const{

	double* arr = allocate1D<double>(order + 1);
	copy_list(arr, _coefs, _order + 1);
	intialize1D(arr + _order + 1, order - _order);

	Poly to_return(arr, order);
	delete[] arr;

	return Poly(to_return);
}

Poly division(const Poly& lhs, const Poly& rhs, Poly& new_poly) {
	new_poly = lhs;
	Poly to_return;
	int i = 0;

	while (new_poly._order >= rhs._order) {
		//*new_poly._coefs / *rhs._coefs = what coefficient to multiply by to equate terms
		double new_coef = *new_poly._coefs / *rhs._coefs;

		/*Make rhs a new polynomial of the correct degree */
		Poly to_subtract(rhs.enlarge_poly_front(new_poly._order));
		//Add quotient term to RETURN polynomial
		to_return = to_return + Term(new_coef, new_poly._order - rhs._order);

		//Multiply by what we're subtracting by the equating coefficient, then subtract it
		to_subtract = to_subtract.multiply_coefs(new_coef);
		new_poly = (new_poly - to_subtract);

	}
	return Poly(to_return);
}

/*Gets the coefficent at a certain order
-----------------------------------------
Preconditions: order is less than or equal to the order of the polynomial
Postconditions: Nothing is changed
*/
double* Poly::get_coeff(int order) const{
	//Get the correct coefficent. _order - order = position of the exponent
	return _coefs + (_order - order);
}

/*Enlarges poly to this "order"
----------------------------------------------------------------------
Preconditions: order is greater than or equal to the the current order
Postconditions: the poly is now enlarged to that order with zeros in the leading positions
*/
Poly Poly::enlarge_poly(int order){
	//Create a new array with the size of the new order
	double* new_array = allocate1D<double>(order + 1);

	//The difference between the orders of the exponent and the polynomial
	int array_difference = order - _order;

	//Copy the old array to the BACK of the new array. The front should have 
	//"array_difference" uninitialized space. order+1 is the size of the array
	copy_list((new_array + array_difference), _coefs, _order + 1);
	//Initialize the front with 0s.
	intialize1D<double>(new_array, array_difference, 0);

	Poly to_return(new_array, order);
	delete[] new_array;

	return Poly(to_return);
}


ostream& operator <<(ostream& outs, const Poly& p) {
	
	outs << "[";
	for (int i = p._order; i >= 1; i--) {
		if (p[i]._coef != 0) {
			outs << p[i] << " + ";
		}
	}
	
    outs << p[0] << "]";
	return outs;
}

void Poly::fix_order() {
	double* walker = _coefs;
	bool reallocated = false;
	while (*walker == 0 && walker < walker+_order) {
		_order--;
		walker++;
		reallocated = true;
	}
	if (reallocated) {
		/*Can't be done with constructor*/

		//Create a new array the size of the new order
		double* new_coefs = allocate1D<double>(_order + 1);
		//Copy the list into this new array, starting at walker
		copy_list(new_coefs, walker, _order + 1);

		//Set this new array as the coefficients
		delete[] _coefs;
		_coefs = new_coefs;
	}
}

istream& operator >>(istream& ins, Poly& p) {
	double coef;
	unsigned int exponent;
	char x, up;

	p = Poly();

	do {
		ins >> coef >> x >> up >> exponent;
		p = p + Term(coef, exponent);
	} while (exponent != 0);

	return ins;
}

bool operator >(const Poly& lhs, const Poly& rhs) {
	if (lhs < rhs || lhs == rhs) {
		return false;
	}
	else
		return true;
}

bool operator <(const Poly& lhs, const Poly& rhs) {
	bool greater = false;
	if (lhs._order < rhs._order) {
		greater = true;
	}
	else if (lhs._order == rhs._order) {
		//Now we check the coefficents
		for (int i = lhs._order; i >= 0; i--) {
			if (lhs[i] < rhs[i]) {
				greater = true;
				break;
			}
			else if (lhs[i] > rhs[i]) {
				break;
			}
		}
	}

	return greater;
}

bool operator ==(const Poly& lhs, const Poly& rhs) {
	//Assume true, prove false
	bool equal = true;

	if (lhs._order == rhs._order) {
		//Check the coefficents
		for (int i = lhs._order; i >= 0; i--) {
			if (lhs[i] != rhs[i]) {
				equal = false;
				break;
			}
		}
	}
	else {
		equal = false;
	}
	return equal;
}

bool operator !=(const Poly& lhs, const Poly& rhs) {
	if (lhs == rhs) {
		return false;
	}
	else
		return true;
}

Poly::~Poly(){
	delete this->_coefs;
}