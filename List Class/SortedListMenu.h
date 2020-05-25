#ifndef Z_SLISTMENU_H
#define Z_SLISTMENU_H

#include "SortedList.h"

void s_initializeList(SortedList<int>& l);
void s_menu(SortedList<int>& l);
//Main menu of cursor program
void s_print(const SortedList<int>& l, SortedList<int>::Iterator cursor);
//Print for the cursor program
void s_random(SortedList<int>& l, SortedList<int>::Iterator& cursor);
//Inserts a random number after the cursor, or, if the list is empty, the head of the list
void s_insert(SortedList<int>& l, SortedList<int>::Iterator& cursor);
////Inserts a user-generated number
void s_Search(SortedList<int>& l, SortedList<int>::Iterator& cursor);
//Searches for the item and updates the cursor if it is found
int getInput();
//Gets user input


#endif