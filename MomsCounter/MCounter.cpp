#include "MCounter.h"
//look at error description on canvas

MCounter::MCounter() {
	the_count = 0;
	internal_error = false;  //There is no error right now
}

//Adds any amount to count if the counter has not overflowed
int MCounter::increment(int to_add) {
	if (!bool(internal_error)) {
		the_count += to_add;
	}
	this->is_error(); //checks if there is now an error
	return the_count;
}

//Adds 1 to count
int MCounter::add_1() {
	this->increment(1);
	return the_count;
}

//Adds 10 to count
int MCounter::add_10() {
	this->increment(10);
	return the_count;
}

//Adds 100 to count
int MCounter::add_100() {
	this->increment(100);
	return the_count;
}

//Adds 1000 to count
int MCounter::add_1000() {
	this->increment(1000);
	return the_count;
}

//Resets the count to 0 and clears the internal error state
int MCounter::reset() {
	the_count = 0;
	internal_error = 0;
	return the_count;
}

//Returns the current count
int MCounter::count() const{
	return the_count;
}

//Checks if there is an error with the count
int MCounter::is_error() {

	//If the count has overflowed
	if (the_count > 9999 || the_count < 0) {
		internal_error = 1;
		the_count = -1;
	}
	else
		internal_error = 0; //There is no error

	return internal_error;
}

//Returns the internal error state
int MCounter::error() const {
	return internal_error;
}

//Returns an description of the internal error
string MCounter::error_description() {
	string the_error = "no error";
	
	//If the counter has overflowed
	if (internal_error == OVERFLOW_ER) {
		return "the count has overflowed";
	}
	return the_error;
}


