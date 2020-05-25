#include "Test_Library.h"

void menu(Poly& P, Poly& Q) {
    char choice;
    cout << "------------------------------";
    do {
        cout << "\n[P]  [Q]     e[X]it: ";
        cin >> choice;
        switch (choice) {
        case 'P':
            cout << "[P]: ";
            cin >> P;
            test_suite(P, Q);
            break;
        case'Q':
            cout << "[Q]: ";
            cin >> Q;
            test_suite(P, Q);
            break;
        case 'X':
            break;
        default:
            cout << "\nInvalid Choice!\n";
        };
    } while (choice != 'X' && choice != 'x');
}
void test_suite(const Poly& P, const Poly& Q) {
    cout << "------------------------------";
    cout << "\nP: " << P;
    cout << "\nQ: " << Q << endl;
    cout << "\n-----------P + Q--------------";
    test_addition(P, Q);
    cout << "\n-----------Q + P--------------";
    test_addition(Q, P);
    cout << "\n-----------P - Q--------------";
    test_subtraction(P, Q);
    cout << "\n-----------Q - P--------------";
    test_subtraction(Q, P);
    cout << "\n-----------P * Q--------------";
    test_mult(P, Q);
    cout << "\n-----------Q * P--------------";
    test_mult(Q, P);
    cout << "\n-----------Q / P--------------\n";
    test_div(Q, P);
    cout << "\n-----------P / Q--------------\n";
    test_div(P, Q);
}

void gen_output(char symbol, const Poly& p, const Poly& q, const Poly& result) {
    cout << endl << p << " " << symbol << " " << q;
    cout << endl << " = " << result << endl;
}

void test_addition(const Poly& p, const Poly& q) {
    gen_output('+', p, q, p + q);
    if (((p + q) - q) == p) {
        cout << "VERIFIED" << endl;
    }
    else {
        cout << endl << "   ***VERIFICATION FAILED" << endl;
        cout << "p + q: " << p + q << endl;
        cout << "p + q - q: " << p + q - q << " != " << q;
    }
}
void test_subtraction(const Poly& p, const Poly& q) {
    gen_output('-', p, q, p - q);
    if (((q - p) + p) == q) {
        cout << "VERIFIED" << endl;
    }
    else {
        cout << endl << "   ***VERIFICATION FAILED" << endl;
        cout << "p - q: " << q - p << endl;
        cout << "p - q + q: " << (q - p) + p << " != " << q;
    }
}
void test_mult(const Poly& p, const Poly& q) {
    gen_output('*', p, q, p * q);
    if ((p * q) / p == q) {
        cout << "VERIFIED" << endl;
    }
    else {
        cout << endl << "   ***VERIFICATION FAILED" << endl;
        cout << "p * q: " << p * q << endl;
        cout << "p * q / q: " << (p * q) / q << " != " << q;
    }
}
void test_div(const Poly& p, const Poly& q) {
    Poly r = p / q;
    cout << p << " / " << q << endl;
    cout << "      = " << r;
    cout << "  rem = " << p % q << "  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if ((r * q) + (p % q) == p) {
        cout << "VERIFIED" << endl;
    }
    else {
        cout << endl << "   ***VERIFICATION FAILED" << endl;
        cout << "   r * q: " << r * q << endl;
        cout << "   p % q: " << p % q << endl;
        cout << "   r * q + p % q: " << r * q + p % q << "=/=" << p << endl;
    }
}

void test_suite1() {
    Term t1(4, 8);
    Term t2(5, 0);
    Term t3(6, 5);
    Term t4(-8, 3);
    Term t5(1, 1);
    double terms[6] = { 3, 4, 0 , 5, 10, 2 };
    double terms2[9] = { 7, 5, 6, 0, 7, 9, 11, 2, 8 };
    double terms3[4] = { 2,1,5,9 };

    double terms4[4] = { 3, -2, 0 , 5 };
    double terms5[3] = { 1, 0, -1 };
    Poly p(terms, 5);
    Poly p2(terms2, 8);
    Poly p3(terms3, 3);
    Poly p5(p);

    Poly div(terms4, 3);
    Poly div2(terms5, 2);

    Poly p4;
    //cin >> p4;
    cout << endl << p4;
    cout << endl << "Printing a term: " << t1;
    cout << endl << "p: " << p;
    cout << "GOT HERE " << endl;
    cout << endl << "p + " << t1 << ": " << p + t1;
    cout << endl << "p + " << t2 << ": " << p + t2;
    cout << endl << "p + " << t3 << ": " << p + t3;
    cout << endl << "p + " << t4 << ": " << p + t4;
    cout << endl << "p2: " << p2;
    cout << endl << "p1 + p2: " << p + p2;
    cout << endl << "p2 + p1: " << p2 + p;
    cout << endl << "p - " << t1 << ": " << p - t1;
    cout << endl << "p - " << t2 << ": " << p - t2;
    cout << endl << "p - " << t3 << ": " << p - t3;
    cout << endl << "p - " << t4 << ": " << p - t4;
    cout << endl << "p1 - p2: " << p - p2;
    cout << endl << "p2 - p1: " << p2 - p;
    cout << endl << "p * " << t4 << ": " << p * t4;
    cout << endl << "p3: " << p3;
    cout << endl << "p * p2: " << p * p3;
    cout << endl << div << " / " << div2;
    cout << endl << div / div2;
    cout << endl << div % div2;
    cout << endl << t1 << " > " << t2 << ": ";
    cout << (t1 > t2);
    cout << endl << t1 << " < " << t2 << ": ";
    cout << (t1 < t2);
    cout << endl << t1 << " != " << t2 << ": ";
    cout << (t1 != t2);
    //t1 = t2;
    cout << endl << t1 << " == " << t2 << ": ";
    cout << (t1 == t2);
    cout << endl << t1 << " != " << t2 << ": ";
    cout << (t1 != t2);
    cout << endl << (p > p2);
    cout << endl << (p < p2);
    cout << endl << (p5 == p);
    cout << endl << (p5 != p);
    cout << endl << (p5 == p2);
    cout << endl << t4 << "/ " << t1 << " = " << t1 / t4;
    cout << endl << t4 / t1;
}