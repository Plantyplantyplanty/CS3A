#include "Stack_test.h"

void test_stack() {
	Stack<string> s;
	Stack<int> s1;

	cout << "STRING STACK\n" << "---------------------------" << endl;
	initialize_string_stack(s);
	cout << "The stack now:\n" << s << endl;
	cout << "Copying stack...\n";
	Stack<string> s_copy(s);
	cout << "Popping:" << endl << "---------------------------" << endl;
	pop_stack(s);
	cout << "\nStack copy: \n"; 
	print_stack(s_copy);
    cout << endl;

	cout << "INT STACK\n" << "---------------------------" << endl;
	intialize_int_stack(s1);
	cout << "The stack now:\n" << s1 << endl;
	cout << "Popping:" << endl << "---------------------------" << endl;
	pop_stack(s1);
	
	cout << endl;
}

void initialize_string_stack(Stack<string>& s) {
	s.push("Bert");
	cout << "Pushing Burt";
	s.push("Billy");
	cout << endl << "Pushing Billy";
	s.push("Noel");
	cout << endl << "Pushing Noel";
	s.push("Ramanujan");
	cout << endl << "Pushing Ramanujan";
	s.push("Roman");
	cout << endl << "Pushing Roman";
	s.push("Nonsense");
	cout << endl << "Pushing Nonsense";
	s.push("No");
	cout << endl << "Pushing No" << endl;
}

void intialize_int_stack(Stack<int>& s) {
	for (int i = 0; i < 9; i++) {
		s.push(-1 * i);
	}
}
void pop_stack(Stack<string>& s) {
	while (s.size() > 0) {
		cout << endl << "Popping " << s.pop();
		cout << endl << "The stack now: \n" << s;
	}
}