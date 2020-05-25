#include "ListMenu.h"

int getInput() {
    int to_insert;

    cout << ": ";
    cin >> to_insert;

    return to_insert;
}
//Inserts 5 random numbers into List
void initializeList(List<int>& l) {
    for (int i = 0; i < 5; i++) {
        //inserts a random number 0 - 100
        l.insert_head(rand() % 100);
    }
}

void print(const List<int>& l, List<int>::Iterator cursor) {
    cout << "H->";
    List<int>::Iterator walker = l.begin();
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

void random(List<int>& l, List<int>::Iterator& cursor) {
    //Inserts a random number 0-100 after where cursor is pointing
    cursor = l.insertAfter((rand() % 100), cursor);
}

void after(List<int>& l, List<int>::Iterator& cursor) {
    int to_insert = getInput();
    cursor = l.insertAfter(to_insert, cursor);
}

void before(List<int>& l, List<int>::Iterator& cursor) {
    int to_insert = getInput();

    cursor = l.insertBefore(to_insert, cursor);
}

void Search(List<int>& l, List<int>::Iterator& cursor) {
    int key = getInput();
    List<int>::Iterator found = l.search(key);
    if (!found.ifNull()) {
        cursor = found;
    }
}


void menu(List<int>& l) {
    char choice;
    List<int>::Iterator cursor = l.begin();

    do {
        print(l, cursor);
        cout << "[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: ";
        cin >> choice;
        switch (choice) {
        case('R'):
        case('r'):
            random(l, cursor);
            break;
        case('A'):
        case('a'):
            after(l, cursor);
            break;
        case('B'):
        case('b'):
            before(l, cursor);
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
            Search(l, cursor);
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