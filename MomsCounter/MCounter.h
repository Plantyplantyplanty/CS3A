#ifndef MCOUNTER_Z
#define MCOUNTER_Z

#include <iostream>
using namespace std;

class MCounter {
public:
    MCounter();
    int add_1();
    int add_10();
    int add_100();
    int add_1000();
    int reset();
    int count() const;
    int error() const;
    string error_description();
private:
    int increment(int to_add);
    int is_error();
    int the_count;
    int internal_error;

    const int OVERFLOW_ER = 1; //Signals an overflow error
};
#endif