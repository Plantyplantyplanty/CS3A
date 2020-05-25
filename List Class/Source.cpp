#include <iostream>
//#include "node_test.h"
#include "list_test.h"
#include "ListMenu.h"
//#include "SortedListMenu.h"
//#include "SortedListTest.h"
/*
 * Author: Marisa Persaud
 * Project: List Class
 * Purpose: Implement a linked list and cursor program
 * Notes: None? Maybe? Please don't hurt me where I used item->next == something code. 
          I just found it easier. It's not often? I did the list class big 3 before
          anything else and it shows.
 *
 * 
 */

int main(){
    List<int> l;
    //SortedList<int> s(false, false);
    test_suite();
    initializeList(l);
    *l.begin() = 5;
    menu(l);
   // s_test_suite(true);
    //s_test_suite(false);
    //s_initializeList(s);
    //s_menu(s);
    return 0;
}

