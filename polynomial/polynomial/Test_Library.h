#pragma once
#ifndef TEST_LIB_H
#define TEST_LIB_H

#include "polynomial.h"

void test_suite1();
void gen_output(char symbol, const Poly& p, const Poly& q, const Poly& result);
void test_div(const Poly& p, const Poly& q);
void test_addition(const Poly& p, const Poly& q);
void test_subtraction(const Poly& p, const Poly& q);
void test_mult(const Poly& p, const Poly& q);
void test_suite(const Poly& P, const Poly& Q);
void menu(Poly& P, Poly& Q);

#endif // !TEST_LIB_H

