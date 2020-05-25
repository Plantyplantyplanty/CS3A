#include "SortedList.h"

int s_getInput() {
    int to_insert;

    cout << ": ";
    cin >> to_insert;

    return to_insert;
}

void s_initializeList(SortedList<int>& l) {
    for (int i = 0; i < 5; i++) {
        //inserts a random number 0 - 100
        l.insert(rand() % 100);
    }
}

void s_print(const SortedList<int>& l, SortedList<int>::Iterator cursor) {
    cout << "H->";
    SortedList<int>::Iterator walker = l.begin();
    while (walker != l.end()) {
        if (walker == cursor) {
            cout << "{" << *walker << "}->";
        }
        else {
            cout << *walker << "->";
        }
        walker++;
    }
    cout << "|||" << endl;
}

void s_random(SortedList<int>& l, SortedList<int>::Iterator& cursor) {
    //Inserts a random number 0-100 after where cursor is pointing
    cursor = l.insert((rand() % 100));
}

void s_insert(SortedList<int>& l, SortedList<int>::Iterator& cursor) {
    int to_insert = s_getInput();
    cursor = l.insert(to_insert);
}

void s_Search(SortedList<int>& l, SortedList<int>::Iterator& cursor) {
    int key = s_getInput();
    SortedList<int>::Iterator found = l.search(key);
    if (!found.ifNull()) {
        cursor = found;
    }
}

void s_menu(SortedList<int>& l) {
    char choice;
    SortedList<int>::Iterator cursor = l.begin();

    do {
        s_print(l, cursor);
        cout << "[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: ";
        cin >> choice;
        switch (choice) {
        case('R'):
        case('r'):
            s_random(l, cursor);
            break;
        case('I'):
        case('i'):
            s_insert(l, cursor);
            break;
        case('D'):
        case('d'):
            if (l.begin() != nullptr) {
                l.Delete(cursor);
            }
            cursor = l.begin();
            break;
        case('S'):
        case('s'):
            s_Search(l, cursor);
            break;
        case('P'):
        case('p'):
            if (cursor != l.begin()) {
                cursor = l.prev(cursor);
            }
            break;
        case('N'):
        case('n'):
            if (cursor != nullptr && cursor.next() != nullptr) {
                cursor++;
            }
            break;
        case('H'):
        case('h'):
            cursor = l.begin();
            break;
        case('E'):
        case('e'):
            cursor = l.begin();
            break;
        default:
            cout << endl << "Invalid choice! Please re-enter: ";
        }
    } while (choice != 'E' && choice != 'e');
}