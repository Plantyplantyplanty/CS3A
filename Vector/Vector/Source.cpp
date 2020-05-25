#include "Vector.h"
#include "AddEntry.h"

/*
 * Author: Marisa Persaud
 * Project: Vector class
 * Purpose: Implement a vector
 * Notes: Testing thoroughly screwed me
 *
 */
void main_test();

int main() {
	main_test();
	return 0;
}

void main_test(){
	Vector<int> v1(5);
	//Bracket operator used in outs, so it obviously works
	cout << "v1 size: " << v1.size() << " v1 capacity: " << v1.capacity() << endl;

	int num;
	cout << "Pushing back 40 with push_back" << endl;
	v1.push_back(40);
	cout << "Pushing back 1-5 with +=: ";
	for (int i = 0; i < 5; i++) {
		num = i;
		v1 += i;
	}
	cout << v1;
	cout << "v1: Printing vector using .at: ";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << "\nv1: Insert 21-26 at [3]: ";
	for (int i = 0; i < 5; i++) {
		v1.insert(3, 21 + i);
		cout << v1;
	}


	cout << "\nv1: Insert 15 at [0]: ";
	v1.insert(0, 15);
	cout << "\nv1: Insert 47 at end: ";
	v1.insert(v1.size(), 47);
	cout << v1 << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Erasing v[" << i << "] :";
		v1.erase(i);
		cout << v1;
	}

	cout << "\nFind me(40): " << v1.index_of(40) << endl;
	cout << "Find me(47): " << v1.index_of(47) << endl;
	cout << "Find me(22): " << v1.index_of(22) << endl;
	cout << "Find me(55): " << v1.index_of(55) << endl;

	cout << "v1 front: " << v1.front() << endl;
	cout << "v1 back: " << v1.back() << endl;

	cout << "\nNew vector copy of v1, v3: ";
	Vector<int> v3(v1);
	cout << v3;
	cout << "Increasing size of v3 to 30: ";
	v3.set_size(30);
	cout << v3;

	cout << "\nv1: " << v1;
	cout << "Popping back v1: ";
	for (int i = 0; i < 10; i++) {
		cout << "Erasing v[" << 0 << "] :";
		v1.erase(0);
		cout << v1;
		//cout << "pop_back: " << v1.pop_back() << endl;
		//cout << endl;
	}

	v3 = v3;
	cout << "v3 = v3: ";
	cout << v3 << endl;
	v1 = v3;
	cout << "v1 = v3: ";
	cout << v1;
	cout << "v1 == v3: ";
	cout << (v1 == v3) << endl;
	v1.erase(3);
	cout << "v1 erase 3: " << v1;
	cout << "v3: " << v3;
	cout << "\nv1 == v3: ";
	cout << (v1 == v3) << endl;
}