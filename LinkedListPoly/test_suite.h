#ifndef TEST_LIB_H
#define TEST_LIB_H

#include "Polynomial.h"
//prints out "p symbol q" "=" p symbol q. The result of p symbol q is stored in "result"
void gen_output(char symbol, const Poly& p, const Poly& q, const Poly& result);

/*Operation testers*/
void test_div(const Poly& p, const Poly& q);
void test_addition(const Poly& p, const Poly& q);
void test_subtraction(const Poly& p, const Poly& q);
void test_mult(const Poly& p, const Poly& q);

void test_suite(const Poly& P, const Poly& Q);
/*Program menu*/
void menu(Poly& P, Poly& Q);

#endif // !TEST_LIB_H

