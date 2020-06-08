#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run:
//---------------------------------------------------------------------

Prefix expression: H->[3]->[*]->[5]->[+]->[4]->||| //3 * 5 + 4
Shunting yard object: 3 5 * 4 +
After assigning to old queue: H->[3]->[5]->[*]->[4]->[+]->|||


Prefix expression: H->[3]->[^]->[(]->[8]->[+]->[5]->[)]->[^]->[4]->||| //3 ^(8 + 5) ^ 4
Shunting yard object: 3 8 5 + 4 ^ ^
After assigning to old queue: H->[3]->[8]->[5]->[+]->[4]->[^]->[^]->|||


Prefix expression: H->[3]->[+]->[5]->[*]->[2]->[^]->[4]->||| //3 + 5 * 2^4
Shunting yard object: 3 5 2 4 ^ * +
After assigning to old queue: H->[3]->[5]->[2]->[4]->[^]->[*]->[+]->|||


Prefix expression: H->[3]->[*]->[(]->[5]->[+]->[8]->[)]->[/]->[2]->|||
Shunting yard object: 3 5 8 + * 2 /
After assigning to old queue: H->[3]->[5]->[8]->[+]->[*]->[2]->[/]->|||

//(3+5) * (8-3)
Prefix expression: H->[(]->[3]->[+]->[5]->[)]->[*]->[(]->[8]->[-]->[3]->[)]->|||
Shunting yard object: 3 5 + 8 3 - *
After assigning to old queue: H->[3]->[5]->[+]->[8]->[3]->[-]->[*]->|||

//3/(5-(6 + 7)/(2 + 8 * 4)) * 9
Prefix expression: H->[3]->[/]->[(]->[5]->[-]->[(]->[6]->[+]->[7]->[)]->[/]->[(]->[2]->[+]->[8]->[*]->[4]->[)]->[)]->[*]->[9]->|||
Shunting yard object: 3 5 6 7 + 2 8 4 * + / - / 9 *
After assigning to old queue: H->[3]->[5]->[6]->[7]->[+]->[2]->[8]->[4]->[*]->[+]->[/]->[-]->[/]->[9]->[*]->|||



C:\Users\Manth\source\repos\ShuntingYard\Debug\ShuntingYard.exe (process 13836) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/

#endif