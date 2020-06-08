#include "fileHandler.h"

void fileHandler::saveFunctions(Queue<string>& oldEq) {
    old_equations.open("old_equation.txt", fstream::app);

    if (old_equations.is_open()) {
        while (oldEq.size() > 0) {
            string to_write = oldEq.pop();

            //Strips the white spaces from the string
            stripSpaces(to_write);
            //If the equation isn't in the file, write it
            if (to_write.size() > 0 && !(searchFile(to_write))) {
                old_equations << to_write << endl;
            }
        }
    }
    old_equations.close();
}

bool fileHandler::searchFile(string& str) {
    ifstream search;
    string inside;
    bool found = false;
    search.open("old_equation.txt");

    while (getline(search, inside)) {
        stripSpaces(inside);
        if (inside == str) {
            found = true;
        }
    }
    search.close();

    return found;
}

void fileHandler::stripSpaces(string& str) {
    //Strip away white spaces
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] == ' ') || (str[i] == '\n')) {
            str.erase(i, 1);
        }
    }
}