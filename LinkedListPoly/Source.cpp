#include "test_suite.h"

/*
 * Author: Marisa Persaud
 * Project: Linked List Polynomial
 * Purpose: Add, subtract, multiply, and divide a linked-list based polynomial 
 * Notes: As soon as you left, people had questions
 *
 */

//Not used in final version
void test(Poly& p, const Poly& q);
void test_booleans(const Poly& s, const Poly& r);
int main(){
	double coefs[4] = {5,1,2,3};
	Term arr2[5] = { Term(4,4), Term(3,3), Term(2,2), Term(1,1), Term(5,0) };
	Term arr3[1] = { Term(3, 8) };
	Term arr4[2] = { Term(3, 8), Term(2,0)};

	Poly s(arr3, 1);
	Poly r(arr4, 2);
	//Test both initialization constructors
	Poly p(coefs, 4);
	Poly q(arr2, 5);

	//Run the boolean checks
	test_booleans(s, r);
	test_booleans(p, q);
	//Run the test suite on the initialized polys
	test_suite(p, q);
	//Run the program menu
	menu(p, q);
	
	return 0;

}

void test_booleans(const Poly& s, const Poly& r) {
	cout << s << " < " << r << "=" << (s < r) << endl;
	cout << s << " > " << r << "=" << (s > r) << endl;
	cout << s << " <= " << r << "=" << (s <= r) << endl;
	cout << r << " >= " << r << "=" << (s >= r) << endl << endl << endl;
}

void test(Poly& p, const Poly& q) {
	cout << p << endl;
	cout << q << endl;
	cout << "p + q: " << p + q << endl;
	cout << "q + p " << q + p << endl;

	cout << "p - q: " << p - q << endl;
	cout << "q - p " << q - p << endl;

	cout << "p * q: " << p * q << endl;
	cout << "q * p " << q * p;
	cin >> p;
	cout << p;
}