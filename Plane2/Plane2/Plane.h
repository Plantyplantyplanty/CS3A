#ifndef PLANE_Z
#define PLANE_Z

#include "2DPointerLibrary.h"
using namespace std;

int * initialize_sizes(int* sizes, int size, int column_size);
/*Initializes the sizes array*/

void plane_initialize(bool** &two_d, const int column_length, const int num_rows, int* &sizes);
/*Initalizes the backbone arrays*/

void menu(bool** two_d, const int column_length, const int num_rows, int* sizes);
/*The main driver of the program. Asks if a user wants to reserve, cancel, or quit.*/

bool reserve(const int* sizes, bool** rows, const int rows_size, int row, char column);
/*Reserves a seat where at row, column*/

bool cancel(const int* sizes, bool** rows, const int rows_size, int row, char column);
/*Cancels the reservation at row, column*/

void plane_print(const int* sizes, bool** rows);
/*Outputs the plane to the terminal*/
#endif