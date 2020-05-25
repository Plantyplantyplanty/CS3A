#ifndef POLY_H
#define POLY_H

#include "SortedList.h"
#include "term.h"

class Poly {

public:
    /*Constructors*/
    Poly();
    //Takes an array of terms of order+1 size and pushes them into the poly
    Poly(Term term_array[], int order);
    //Takes an array of coefs of "size" size and pushes them into the poly
    //assuming the subscript is the exponent
    Poly(double coefs[], int size);

    /*Operators for poly and term*/
    friend Poly operator + (const Poly& left, const Term& t);
    friend Poly operator * (const Poly& left, const Term& t);

    /*()= for Poly and term*/
    Poly& operator +=(const Term& t);
    Poly& operator *=(const Term& t);

    /*()= for Poly and Poly*/
    Poly& operator +=(const Poly& RHS);
    Poly& operator *=(const Poly& RHS);
    Poly& operator -=(const Poly& RHS);
    Poly operator -() const;

    /*Operators for Poly and Poly*/
    friend Poly operator + (const Poly& left, const Poly& right);
    friend Poly operator -(const Poly& left, const Poly& right);
    friend Poly operator * (const Poly& left, const Poly& right);
    friend Poly operator /(const Poly& lhs, const Poly& rhs);
    //I prefer to do mod the way I have done it
    friend Poly operator %(const Poly& lhs, const Poly& rhs);

    //Divides lhs and rhs. Returns the quotient and sets "remainder" to mod
    friend Poly division(const Poly& lhs, const Poly& rhs, Poly& remainder);

    friend bool operator ==(const Poly& lhs, const Poly& rhs);
    friend bool operator !=(const Poly& lhs, const Poly& rhs);
    friend bool operator >(const Poly& lhs, const Poly& rhs);
    friend bool operator <(const Poly& lhs, const Poly& rhs);
    friend bool operator >=(const Poly& lhs, const Poly& rhs);
    friend bool operator <=(const Poly& lhs, const Poly& rhs);

    //Stream operators
    friend ostream& operator << (ostream& outs, const Poly& print_me);
    friend istream& operator >> (istream& ins, Poly& add_to_me);

    void fixOrder(); //Gets rid of ALL zero terms in a non-empty poly

private: 
    //A SortedList with "Term"s as the items
    SortedList<Term> _poly;
};
#endif