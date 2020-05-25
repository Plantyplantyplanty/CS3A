#ifndef LAB_H
#define LAB_H

#include "2DPointerLibrary.h"

void initialize(int** &lab, const int num_rows, const int false_value, int *sizes);
/*Initializes lab and sizes*/

void menu(int** lab, int* sizes, int num_rows, int false_value);
/*The main driver of the program, logging users in and out until quitting*/

bool login(int** lab, const int* sizes, const int num_rows, int ID, const int station, const int lab_num, const int empty_value);
/*Logs in to the lab at the requested station, lab*/

bool logout(int** lab, const int* sizes, const int num_rows, int ID, const int false_value);
/*Logs out of the lab at the requested station, lab*/

bool lab_logout(int** lab, const int num_rows, const int row, const int size, const int* sizes, const int ID, const int false_value, bool logged_out);
/*Logs out of a specific lab. Terrible, terrible definition, would rather do the double for loop*/

void lab_print(const int * sizes, int ** lab, const int false_value);
/*Prints the lab using 2D Pointer's function*/

#endif