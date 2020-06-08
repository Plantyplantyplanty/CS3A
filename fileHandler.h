#pragma once
#include <string>
#include <fstream>
#include "Queue.h"

class fileHandler{
public:
	fileHandler(){}
    void saveFunctions(Queue<string>& oldEq);               //Saves the functions in the oldEq stack
    void stripSpaces(string& str);      //strips the white spaces from a string
    bool searchFile(string& str); //searches if a function is within the output files
                                           //before writing it
private:
    ofstream old_equations;             //The file with the old equations in it
};

