#include "test_suite.h"


void menu(Poly& P, Poly& Q) {
    char choice;
    cout << "------------------------------";
    do {
        cout << "\n[P]  [Q]     e[X]it: ";
        cin >> choice;
        switch (choice) {
        case 'P':
        case 'p':
            cout << "[P]: ";
            cin >> P;
            test_suite(P, Q);
            break;
        case'Q':
        case 'q':
            cout << "[Q]: ";
            cin >> Q;
            test_suite(P, Q);
            break;
        case 'X':
        case'x':
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
    cout << "\n-----------P / Q--------------\n";
    test_div(P, Q);
    cout << "\n-----------Q / P--------------\n";
    test_div(Q, P);
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
    else{
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

