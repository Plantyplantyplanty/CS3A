#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run:
//---------------------------------------------------------------------
------------------START------------------
Enter in the number of rows on the plane: 7
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D


Enter in the row and column you would like to reserve: 1A
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 X B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D


Enter in the row and column you would like to reserve: 7D
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 X B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C X


Enter in the row and column you would like to reserve: 3B
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 X B C D
2 A B C D
3 A X C D
4 A B C D
5 A B C D
6 A B C D
7 A B C X


Enter in the row and column you would like to reserve: 5C
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 X B C D
2 A B C D
3 A X C D
4 A B C D
5 A B X D
6 A B C D
7 A B C X


Enter in the row and column you would like to reserve: 7D
That seat is already reserved. Sorry!
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : C

This is the plane now. There is an X in reserved seats:
1 X B C D
2 A B C D
3 A X C D
4 A B C D
5 A B X D
6 A B C D
7 A B C X


Enter in the row and column you would like to cancel: 1A
That seat has been cancelled.
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : C

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B C D
3 A X C D
4 A B C D
5 A B X D
6 A B C D
7 A B C X


Enter in the row and column you would like to cancel: 7D
That seat has been cancelled.
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : Q

This is the plane:
1 A B C D
2 A B C D
3 A X C D
4 A B C D
5 A B X D
6 A B C D
7 A B C D

------------------GOOODBYE-------------------------

C:\Users\Manth\source\repos\Plane2\x64\Debug\Plane2.exe (process 24392) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
//---------------------------------------------------------------------
// Reserving a seat that does not exist/Cancelling an invalid seat
//---------------------------------------------------------------------
------------------START------------------
Enter in the number of rows on the plane: 9
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D
8 A B C D
9 A B C D


Enter in the row and column you would like to reserve: 2C
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B X D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D
8 A B C D
9 A B C D


Enter in the row and column you would like to reserve: 5B
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B X D
3 A B C D
4 A B C D
5 A X C D
6 A B C D
7 A B C D
8 A B C D
9 A B C D


Enter in the row and column you would like to reserve: 9A
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B X D
3 A B C D
4 A B C D
5 A X C D
6 A B C D
7 A B C D
8 A B C D
9 X B C D


Enter in the row and column you would like to reserve: 4A
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : C

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B X D
3 A B C D
4 X B C D
5 A X C D
6 A B C D
7 A B C D
8 A B C D
9 X B C D


Enter in the row and column you would like to cancel: 2B
That seat is not reserved. Sorry!
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B X D
3 A B C D
4 X B C D
5 A X C D
6 A B C D
7 A B C D
8 A B C D
9 X B C D


Enter in the row and column you would like to reserve: 9F
Assertion failed: valid, file C:\Users\Manth\source\repos\Plane2\Plane2\2DPointerLibrary.h, line 230

C:\Users\Manth\source\repos\Plane2\x64\Debug\Plane2.exe (process 22292) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// Cancelling a seat that does not exist
//---------------------------------------------------------------------
------------------START------------------
Enter in the number of rows on the plane: 4
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C D
2 A B C D
3 A B C D
4 A B C D


Enter in the row and column you would like to reserve: 1D
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C X
2 A B C D
3 A B C D
4 A B C D


Enter in the row and column you would like to reserve: 2D
Would you like to reserve a seat(R), cancel(C) or quit(Q)? : R

This is the plane now. There is an X in reserved seats:
1 A B C X
2 A B C X
3 A B C D
4 A B C D


Enter in the row and column you would like to reserve: 5A
Assertion failed: valid, file C:\Users\Manth\source\repos\Plane2\Plane2\2DPointerLibrary.h, line 230

C:\Users\Manth\source\repos\Plane2\x64\Debug\Plane2.exe (process 14028) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
#endif
