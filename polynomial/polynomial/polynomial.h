#ifndef POLY_H
#define POLY_H

#include "term.h"
#include "1DLibrary.h"
#include "AddEntry.h"

class Poly {
private:
	double* _coefs;
	int _order;
	double* get_coeff(int order) const;
	/*Gets the coefficent at a certain order*/
	Poly enlarge_poly(int order);
	/*Enlarges poly to this order with 0s in the FRONT*/
	Poly multiply_coefs(double coeff);
	void copy_poly(const Poly& rhs);
	void fix_order();
	/*Gets rid of ALL leading 0 terms*/
	Poly enlarge_poly_front(int order) const;
	/*Enlarges poly to this order with 0s in the BACK*/
public:
	//array of 1 with a 0 in it
	Poly();
	Poly(double* coefs, int order);
	Poly(const Poly& original);
	Poly& operator =(const Poly& rhs);
	~Poly();

	Term operator[](int order) const;

	friend bool operator >(const Poly& lhs, const Poly& rhs);
	friend bool operator <(const Poly& lhs, const Poly& rhs);

	friend Poly operator +(const Poly& lhs, const Term& t);
	friend Poly operator +(const Poly& lhs, const Poly& rhs);
	
	friend Poly operator -(const Poly& p, const Term& t);
	friend Poly operator - (const Poly& lhs, const Poly& rhs);

	friend Poly operator *(const Poly& lhs, const Term& t);
	friend Poly operator *(const Poly& lhs, const Poly& rhs);

	friend Poly operator /(const Poly& lhs, const Poly& rhs);
	friend Poly operator %(const Poly& lhs, const Poly& rhs);
	friend Poly division(const Poly& lhs, const Poly& rhs, Poly& new_poly);

	friend bool operator ==(const Poly& lhs, const Poly& rhs);
	friend bool operator !=(const Poly& lhs, const Poly& rhs);

	friend ostream& operator <<(ostream& outs, const Poly& p);
	friend istream& operator >>(istream& ins, Poly& p);

	int order() const { return _order; }
};
#endif 