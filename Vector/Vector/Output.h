#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run:
//---------------------------------------------------------------------

v1 size: 0 v1 capacity: 5
Pushing back 40 with push_back
Pushing back 1-5 with +=:
Reallocating list capacity from 5 to 10
40 0 1 2 3 4
v1: Printing vector using .at: 40 0 1 2 3 4
v1: Insert 21-26 at [3]: 40 0 1 21 2 3 4

Reallocating list capacity from 10 to 20
40 0 1 22 21 2 3 4
40 0 1 23 22 21 2 3 4
40 0 1 24 23 22 21 2 3 4
40 0 1 25 24 23 22 21 2 3 4

v1: Insert 15 at [0]:
v1: Insert 47 at end: 15 40 0 1 25 24 23 22 21 2 3 4 47

Erasing v[0] :40 0 1 25 24 23 22 21 2 3 4 47
Erasing v[1] :40 1 25 24 23 22 21 2 3 4 47
Erasing v[2] :40 1 24 23 22 21 2 3 4 47

Find me(40): 0
Find me(40): 9
Find me(22): 4
Find me(55): -1
v1 front: 40
v1 back: 47

New vector copy of v1, v3: 40 1 24 23 22 21 2 3 4 47
Increasing size of v3 to 30:
Reallocating list capacity from 10 to 60
40 1 24 23 22 21 2 3 4 47 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

v1: 40 1 24 23 22 21 2 3 4 47
Popping back v1: pop_back: 47

pop_back: 4

pop_back: 3

pop_back: 2

pop_back: 21

pop_back: 22

pop_back: 23

pop_back: 24


Reallocating list capacity from 10 to 5
pop_back: 1


Reallocating list capacity from 5 to 2
pop_back: 40

v3 = v3: 40 1 24 23 22 21 2 3 4 47 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

v1 = v3: 40 1 24 23 22 21 2 3 4 47 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
v1 == v3: 1
v1 erase 3: 40 1 24 22 21 2 3 4 47 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
v3: 40 1 24 23 22 21 2 3 4 47 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

v1 == v3: 0

C:\Users\Manth\source\repos\Vector\Debug\Vector.exe (process 31312) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//This fails when presented with empty vectors or negative sizes, but it's hard to show
since this doesn't have an interface. For example:

Erase:
Assertion failed: erase_index >= 0 && erase_index <= _size && _size > 0, file C:\Users\Manth\source\repos\Vector\Vector\Vector.h, line 247
Pop_back:
Assertion failed: !empty(), file C:\Users\Manth\source\repos\Vector\Vector\Vector.h, line 373
Negative size:
Assertion failed: capacity >= 0, file C:\Users\Manth\source\repos\Vector\Vector\AddEntry.h, line 102
Out of Bounds Insert:
Assertion failed: insert_here >= 0 && insert_here <= _size, file C:\Users\Manth\source\repos\Vector\Vector\Vector.h, line 227
*/

#endif