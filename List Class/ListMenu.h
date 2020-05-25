#ifndef Z_LISTMENU_H
#define Z_LISTMENU_H

#include "linked_list.h"
void initializeList(List<int>& l);
void menu(List<int>& l);
//Main menu of cursor program
void print(const List<int>& l, List<int>::Iterator cursor);
//Print for the cursor program
void random(List<int>& l, List<int>::Iterator& cursor);
//Inserts a random number after the cursor, or, if the list is empty, the head of the list
void after(List<int>& l, List<int>::Iterator& cursor);
//Inserts a user-generated number after the cursor, or if the list is empty, the head of list
void before(List<int>& l, List<int>::Iterator& cursor);
////Inserts a user-generated number before the cursor, or if the list is empty, the head of list
void Search(List<int>& l, List<int>::Iterator& cursor);
//Searches for the item and updates the cursor if it is found
int getInput();
//Gets user input


#endif