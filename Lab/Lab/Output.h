#ifndef OUTPUT_Z.H
#define OUTPUT_Z.H

/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// Normal run:
//---------------------------------------------------------------------
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 123




No student ID of that number detected               //Logout works when lab empty
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?A  //Does not accept invalid choices

Invalid choice
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 123
Enter in your lab #: 2
Enter in your station #: 3

You have been logged in to station 3, lab number 2
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: 123 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 123
Enter in your lab #: 1
Enter in your station #: 1

You have been logged in to station 1, lab number 1       //First edge case
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: 123 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 123
Enter in your lab #: 4
Enter in your station #: 2

You have been logged in to station 2, lab number 4     //Second edge case
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: 123 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 456
Enter in your lab #: 3
Enter in your station #: 1

You have been logged in to station 1, lab number 3
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: 123 4: Empty 5: Empty
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 456
Enter in your lab #: 2
Enter in your station #: 5

You have been logged in to station 5, lab number 2
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: 123 4: Empty 5: 456
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 780
Enter in your lab #: 2
Enter in your station #: 1

You have been logged in to station 1, lab number 2
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: 780 2: Empty 3: 123 4: Empty 5: 456
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 900
Enter in your lab #: 2
Enter in your station #: 2

You have been logged in to station 2, lab number 2
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: 780 2: 900 3: 123 4: Empty 5: 456
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 211
Enter in your lab #: 1
Enter in your station #: 1
That station is already taken or invalid                //Trying to take a taken station
This is the lab now:
1: 1: 123 2: Empty 3: Empty 4: Empty
2: 1: 780 2: 900 3: 123 4: Empty 5: 456
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: 123
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 123



 
Successfully logged out                             //Successful logout of multiple stations
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: 780 2: 900 3: Empty 4: Empty 5: 456
3: 1: 456 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 456




Successfully logged out
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: 780 2: 900 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 201
Enter in your lab #: 3
Enter in your station #: 1

You have been logged in to station 1, lab number 3
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: 780 2: 900 3: Empty 4: Empty 5: Empty
3: 1: 201 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 780                         //Successful logout of a single station




Successfully logged out
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: 900 3: Empty 4: Empty 5: Empty
3: 1: 201 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 455




No student ID of that number detected                   //Still will not logout invalidly
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: 900 3: Empty 4: Empty 5: Empty
3: 1: 201 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 201




Successfully logged out
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: 900 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?O

Enter in your ID number: 900




Successfully logged out
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?Q

This is the lab at quitting time:                         //Shows the lab when quitting
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty

C:\Users\Manth\source\repos\Lab\Debug\Lab.exe (process 11568) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// Attempting to login to an invalid lab:
//---------------------------------------------------------------------
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)? I

Enter in your ID number: 124
Enter in your lab #: 3
Enter in your station #: 2

You have been logged in to station 2, lab number 3
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: 124 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 456
Enter in your lab #: 5
Enter in your station #: 2
 Column valid Assertion failed: valid, file C:\Users\Manth\source\repos\Lab\Lab\2DPointerLibrary.h, line 183

C:\Users\Manth\source\repos\Lab\Debug\Lab.exe (process 14420) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// Attempting to login to an invalid station:
//---------------------------------------------------------------------
This is the lab now:
1: 1: Empty 2: Empty 3: Empty 4: Empty
2: 1: Empty 2: Empty 3: Empty 4: Empty 5: Empty
3: 1: Empty 2: Empty 3: Empty
4: 1: Empty 2: Empty
Would you like to login(I), logout(O), or quit(Q)?I

Enter in your ID number: 123
Enter in your lab #: 2
Enter in your station #: 7
 Column valid Assertion failed: valid, file C:\Users\Manth\source\repos\Lab\Lab\2DPointerLibrary.h, line 183

C:\Users\Manth\source\repos\Lab\Debug\Lab.exe (process 12000) exited with code 3.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/

#endif
