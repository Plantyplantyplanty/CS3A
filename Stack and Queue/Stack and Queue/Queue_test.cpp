#include "Queue_test.h"
using namespace std;

void test_queue() {
	Queue<string> q;
	Queue<int> q1;
	//q.pop();
	cout << "STRING QUEUE\n" << "---------------------------" << endl;
	initialize_string_queue(q);
	cout << "The queue is now:\n" << q << endl;
	cout << "Copying queue...\n";
	Queue<string> q_copy(q);
	cout << "Popping:" << endl << "---------------------------" << endl;
	pop_queue(q);
	cout << "\nQueue copy: \n";
	print_queue(q_copy);
	cout << endl;

	cout << "INT QUEUE\n" << "---------------------------" << endl;
	intialize_int_queue(q1);
	cout << "The queue now:\n" << q1 << endl;
	cout << "Popping:" << endl << "---------------------------" << endl;
	pop_queue(q1);

	cout << endl;
}

void initialize_string_queue(Queue<string>& q) {
	q.push("Bert");
	cout << "Pushing Burt";
	q.push("Billy");
	cout << endl << "Pushing Billy";
	q.push("Noel");
	cout << endl << "Pushing Noel";
	q.push("Ramanujan");
	cout << endl << "Pushing Ramanujan";
	q.push("Roman");
	cout << endl << "Pushing Roman";
	q.push("Nonsense");
	cout << endl << "Pushing Nonsense";
	q.push("No");
	cout << endl << "Pushing No" << endl;
	cout << "The end's size: " << q.end()->size() << endl;
	cout << "The beginning's size: " << q.begin()->size() << endl;
}

void intialize_int_queue(Queue<int>& q) {
	for (int i = 0; i < 9; i++) {
		q.push(-1 * i);
	}
}
