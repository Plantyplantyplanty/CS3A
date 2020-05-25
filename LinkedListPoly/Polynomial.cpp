#include "Polynomial.h"

Poly::Poly(){
	//Creates a polynomial with a 0^0 term
	_poly.insert(Term(0,0));
}

/*Inserts all of the terms in the array into poly*/
Poly::Poly(Term term_array[], int size) {
	for (int i = 0; i < size; i++) {
		_poly.insert(term_array[i]);
	}
	//Takes out all 0 terms
	fixOrder();
}

/*Takes an array of coefs of "size" size and pushes them into the poly
assuming the subscript of each coef is its exponent*/
Poly::Poly(double coefs[], int size) {
	for (int i = 0; i < size; i++) {
		_poly.insert(Term(coefs[i],i));
	}
	fixOrder();
}

/*Discards all 0 values in the list besides 0x^0*/
void Poly::fixOrder(){
	SortedList<Term>::Iterator it = _poly.begin(); //Iterates over the list
	SortedList<Term>::Iterator hold; //Holds a value temporarily

	//Get rid of leading zeroes
	while ((it->_coef == 0) && (it.next() != _poly.end())) {
		hold = it.next(); 
		_poly.Delete(it);
		it = hold;
	}

	it = _poly.begin();
	//if it->coef IS 0 after getting of all the leading zeroes, then the last term has a 
	//0 coeff so...
	if (it->_coef != 0) {
		//Iterate through the list to get rid of internal 0s
		while (it != _poly.end()) {
			if (it->_coef == 0) {
				hold = it.next();
				_poly.Delete(it);
				it = hold;
			}
			else { //if it isn't an else then you skip 2 forward when deleting
				it++;
			}
		}
	}
	else {
		//...make SURE the leftover 0 has a 0 coefficient
		_poly.Delete(it);
		_poly.insert(Term(0, 0));
	}
}
//Has double protection against adding 0 terms
Poly& Poly::operator +=(const Term& t) {
	if (t._coef != 0) { //Don't waste time adding in 0s we'll have to take out
		//Calls insert_and_add in SortedList
		_poly.insert(t);
	}
	fixOrder();
	return *this;
}

Poly operator + (const Poly& left, const Term& t) {
	Poly to_return(left); //make to_return a modifiable copy of "left"
	//Calls the += operator
	return (to_return += t);
}

Poly operator * (const Poly& left, const Term& t) {
	SortedList<Term>::Iterator it = left._poly.begin();
	Poly to_return;

	while (it != left._poly.end()) {
		//multiply each term in the polynomial by t. Put the result of each multiplication in a 
		//term and add it what wil be returned. Because we are using +=, 0 terms do not get added.
		to_return += Term(*it * t);
		it++;
	}

	return Poly(to_return);
}

Poly& Poly::operator *=(const Term& t) {
	*this = *this * t;
	return *this;
}

Poly& Poly::operator *=(const Poly& RHS) {
	*this = *this * RHS;
	return *this;
}

Poly operator + (const Poly& left, const Poly& right) {
	Poly to_return(left); //Make a modifiable copy of "left"
	SortedList<Term>::Iterator it = right._poly.begin(); 

	//Add each term in "right" to what we will return. += protects against 0 terms.
	while (it != right._poly.end()) {
		to_return += *it;
		it++;
	}

	//Will get rid of any trailing x^0 terms
	to_return.fixOrder();
	return Poly(to_return);
}

Poly operator -(const Poly& left, const Poly& right) {
	Poly to_return(left); //Make left modifiable
	SortedList<Term>::Iterator it = right._poly.begin(); //iterating over right
	
	while (it != right._poly.end()) {
		//Multiply each term in rhs by -1 and add it to lhs
		//More efficient than calling the unary operator, does it "in one"
		to_return += Term(-(*it));
		it++;
	}

	//Will get rid of any trailing x^0 terms
	to_return.fixOrder();
	return Poly(to_return);
}

/*Makes the poly negative*/
Poly Poly::operator -() const {
	Poly to_return; //starts off empty
	SortedList<Term>::Iterator it = _poly.begin();

	
	while (it != _poly.end()) {
		//Multiple each term by -1, add it to the return poly
		to_return += Term(-(*it));
		it++;
	}

	//Will get rid of any trailing x^0 terms
	to_return.fixOrder();

	return Poly(to_return);
}

Poly& Poly::operator -=(const Poly& RHS) {
	*this = *this - RHS;
	return *this;
}


Poly& Poly::operator +=(const Poly& RHS) {
	*this = *this + RHS;
	return *this;
}


Poly operator * (const Poly& left, const Poly& right) {
	Poly to_return;
	SortedList<Term>::Iterator it = right._poly.begin();

	//Multiply "left" by each term in "right" and add the results together
	while (it != right._poly.end()) {
		to_return += (left * (*it));
		it++;
	}

	//Will get rid of any trailing x^0 terms
	to_return.fixOrder();

	return Poly(to_return);
}

Poly operator /(const Poly& lhs, const Poly& rhs) {
	Poly remainder; //won't get used here
	return division(lhs, rhs, remainder);
}

Poly operator %(const Poly& lhs, const Poly& rhs) {
	Poly remainder; //what gets returned

	division(lhs, rhs, remainder);
	return remainder;
}
Poly division(const Poly& lhs, const Poly& rhs, Poly& remainder) {
    Poly dividend(lhs);
	Poly to_return;

	Term dividend_begin = *(dividend._poly.begin());
	Term rhs_begin = *(rhs._poly.begin());
	assert(rhs_begin._coef != 0); //never divide by 0!

	//while the exponent of the dividend is greater than or equal to that of the divisor
	//dividend_begin._exp >= rhs_begin._exp
	while(dividend_begin >= rhs_begin) {
		Term multiple = dividend_begin / rhs_begin; //We get what the quotient for this term is
		//cout << endl <<  "multiple: " << multiple <<  endl;
		to_return += multiple; //Add it to our polynomial that we're returning

		Poly to_subtract = rhs * multiple;  //Then we multiply the rhs with it
		//cout << endl << "subtract: " << to_subtract << endl;
		dividend = (dividend - to_subtract);   //then subtract that value from dividend.
		//cout << endl << "dividend: " << dividend << endl;
		dividend.fixOrder();  //Delete any 0 terms
		//cout << endl << "fixorder: " << dividend << endl;
		dividend_begin = *(dividend._poly.begin()); //and start the process again
	}
	to_return.fixOrder(); //just in case of trailing zeroes.
	dividend.fixOrder();
	remainder = dividend; 
	return to_return;
}


bool operator ==(const Poly& lhs, const Poly& rhs) {
	bool equal = true;
	SortedList<Term>::Iterator l_it = lhs._poly.begin();
	SortedList<Term>::Iterator r_it = rhs._poly.begin();

	
	while ((l_it != lhs._poly.end()) && (r_it != rhs._poly.end())) {
		//Compare the coefficents and exponents
		if ((l_it->_coef != r_it->_coef) || (l_it->_exp != r_it->_exp)) {
			equal = false;
			break;
		}
		r_it++;
		l_it++;
	}
	//If we've broken, but one of the polys still has terms. This will also double-falsify if 
	//the loop has broken early
	if ((l_it != lhs._poly.end()) || (r_it != rhs._poly.end())){
		equal = false;
	}

	return equal;
}

bool operator >(const Poly& lhs, const Poly& rhs) {
	bool greater = true;
	SortedList<Term>::Iterator l_it = lhs._poly.begin();
	SortedList<Term>::Iterator r_it = rhs._poly.begin();

	//While both polys have terms left in them
	while ((l_it != lhs._poly.end()) && (r_it != rhs._poly.end())) {
		//Compare the exponents and coefficents
		if ((*l_it == *r_it) && (l_it->_coef < r_it->_coef)){
				greater = false;
				break;
	    }
		else if (*l_it < *r_it) {
			greater = false;
			break;
		}
		r_it++;
		l_it++;
	}
	
	//We have not broken early
	if (greater == true) {
		if (((l_it == lhs._poly.end()) && (r_it == rhs._poly.end()))) {
			greater = false;
		}
		else if (r_it != rhs._poly.end()) { //rhs still has terms in it, but lhs doesn't
			greater = false;
		}
	}
	return greater;
}

bool operator <(const Poly& lhs, const Poly& rhs) {
	if ((lhs == rhs) || (lhs > rhs)) {
		return false;
	}
	else
		return true;
}

bool operator >=(const Poly& lhs, const Poly& rhs) {
	if (lhs < rhs) {
		return false;
	}
	else
		return true;
}
bool operator <=(const Poly& lhs, const Poly& rhs) {
	if (lhs > rhs) {
		return false;
	}
	else
		return true;
}

bool operator !=(const Poly& lhs, const Poly& rhs) {
	if (lhs == rhs) {
		return true;
	}
	else
		return false;
}


ostream& operator << (ostream& outs, const Poly& print_me) {
	SortedList<Term>::Iterator it = print_me._poly.begin();
	
	outs << "[";
	//Output all the terms in the poly
	while (it.next() != print_me._poly.end()) {
		outs << *it << " + ";
		it++;
	}
	//Output the last term without a "+" at the end
	outs << *it << "]";

	return outs;
}

istream& operator >> (istream& ins, Poly& add_to_me) {
	double coeff;
	char discard;
	int exp;

	add_to_me = Poly(); //clear add_to_me

	do{      //coeff, x, ^, exp
		ins >> coeff >> discard >> discard >> exp;
		add_to_me += Term(coeff, exp);
	} while (exp != 0);

	add_to_me.fixOrder();
	return ins;
}