#include <iostream>
#include <cstring>
using namespace std;

void get_string(char * s); //get a c-string from input
bool is_palindrome(char * s); //true if s is a palindrome
const bool DEBUG = true;
const int MAX = 10;
char* last_element(char* s);

int main() {
	cout << endl << endl << endl;
	char s[MAX + 1];
	bool done = false;

	do {
		get_string(s);
		if (DEBUG) {
			cout << "DEBUG: main: s |" << s << "|" << endl;
		}
		if (strlen(s) == 0) {
			done = true;
		}
		if (is_palindrome(s)) {
			cout << s << " is a palindrome" << endl;
		}
		else {
			cout << s << " is not a palindrome" << endl;
		}
	} while (!done);

	cout << endl << endl << "====================END=====================" << endl;
	return 0;
}

void get_string(char* s) {
	cin.getline(s, MAX);
	if (DEBUG) {
		cout << "DEBUG: get_string(): s |" << s << "|" << endl;
	}
}

char* last_element(char* s) {
	if (*s == NULL) {
		return nullptr;
	}

	while (*s != NULL) {
		s++;
	}
	return --s;
}


bool is_palindrome(char* s) {
	if (DEBUG) {
		cout << "DEBUG: is_palindrome(): s |" << s << "|" << endl;
	}

	if (*s == NULL) {
		return true;
	}

	char* beginning = s;
	char* rear = last_element(s);
	
	if (DEBUG) {
		cout << "DEBUG: is_palindrome(): s |" << s << "|" << endl;
	}

	bool is_palindrome = true;

	while (rear > beginning) {
		if (*beginning != *rear) {
			is_palindrome = false;
		}
		rear--;
		beginning++; 
	}

	return is_palindrome;
}