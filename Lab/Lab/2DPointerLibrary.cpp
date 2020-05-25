#include "2DPointerLibrary.h"

/*Returns if the entry at (rows[row-1], rows[row-1][column - 1]) exists
-----------------------------------------------------------------------
Preconditions: "sizes" contains the valid sizes of all of the arrays in the list; "rows_size" is the valid
			   size of the list; "rows_size", "row", and "column" are greater than or equal to 0
Postconditions: All are unchanged.
*/
bool isValid(const int* sizes, const int rows_size, const int row, const int column) {

	assert((sizes != nullptr) && (row >= 0) && (column >= 0));
	bool valid = true;

	//If the row is valid
	if ((row - 1) > rows_size) {
		valid = false;
		cout << " Row valid ";
	}
	else {
		//Go to if the column is valid

		//The size of the array column which is being referenced
		const int* ptr_to_size = sizes + (row - 1);
		int arr_size = *ptr_to_size;
		//cout << arr_size << endl;

		//if the column being asked for is greater than the size of the array
		if (arr_size < (column - 1)) {
			valid = false;
			cout << " Column valid ";
		}
	}
	return valid;
}