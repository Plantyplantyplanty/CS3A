
/*
 * Author: Marisa Persaud
 * Project: Polynomial 
 * Purpose: Create a program to add, subtract, multiply, and divide polynomials
 * Notes: See work report
 */

#include "term.h"
#include "polynomial.h"
#include "Test_Library.h"

int main() {
    double p_array[4] = { 3, 2, 1, 5 };
    double q_array[5] = { 4, 3, 2, 1, 5 };

    //double p2[6] = { 6, 0, 4, 0, -2, 3 };

    Poly P(p_array, 3);
    Poly Q(q_array, 4);
    test_suite(P, Q);

    cout << endl << endl << endl;
    menu(P, Q);

    return 0;
}
