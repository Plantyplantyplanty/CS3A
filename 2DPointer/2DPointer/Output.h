#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// Normal Run
//---------------------------------------------------------------------

0 1
10 11 12 13
20 21 22 23 24 25
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47 48 49

The entry at (1, 1): 0
The entry at (3,3): 22
The entry at (5, 10): 49
The entry at (3, 6): 25

Write (5, 10) with 66:
Write (3, 4) with 66:
Write (1, 1) with 66:

66 1
10 11 12 13
20 21 22 66 24 25
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47 48 66

The entry at (1, 1): 66
C:\Users\Manth\source\repos\2DPointer\Debug\2DPointer.exe (process 26564) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// Tries to write to an undefined location
//---------------------------------------------------------------------
0 1
10 11 12 13
20 21 22 23 24 25
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47 48 49

The entry at(1, 1) : 0
The entry at(3, 3) : 22
The entry at(5, 10) : 49
The entry at(3, 6) : 25

Write(5, 10) with 66 : Assertion failed : !successful_write, file C : \Users\Manth\source\repos\2DPointer\2DPointer\Source.cpp, line 185

C:\Users\Manth\source\repos\2DPointer\Debug\2DPointer.exe(process 27188) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
//---------------------------------------------------------------------
// Tries to read an undefined location
//---------------------------------------------------------------------

0 1
10 11 12 13
20 21 22 23 24 25
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47 48 49

The entry at (1, 1): 0
The entry at (3,3): 22
The entry at (5, 10): 49
The entry at (3, 6): 25Assertion failed: value != nullptr, file C:\Users\Manth\source\repos\2DPointer\2DPointer\Source.cpp, line 169

C:\Users\Manth\source\repos\2DPointer\Debug\2DPointer.exe (process 6384) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/


#endif