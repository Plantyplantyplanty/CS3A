#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

/*
***** ALL RESULTS ARE VERIFIED ******
*************************************
STACK
*************************************
//---------------------------------------------------------------------
// popping an empty stack:
//---------------------------------------------------------------------
Assertion failed: head != nullptr, file C:\Users\Manth\source\repos\Stack and Queue\Stack and Queue\Node.h, line 214
//---------------------------------------------------------------------
// Normal Run:
//---------------------------------------------------------------------
STRING STACK
---------------------------
Pushing Burt
Pushing Billy
Pushing Noel
Pushing Ramanujan
Pushing Roman
Pushing Nonsense
Pushing No
The stack now:
H->[No]->[Nonsense]->[Roman]->[Ramanujan]->[Noel]->[Billy]->[Bert]->|||
Copying stack...
Popping:
---------------------------

Popping No
The stack now:
H->[Nonsense]->[Roman]->[Ramanujan]->[Noel]->[Billy]->[Bert]->|||
Popping Nonsense
The stack now:
H->[Roman]->[Ramanujan]->[Noel]->[Billy]->[Bert]->|||
Popping Roman
The stack now:
H->[Ramanujan]->[Noel]->[Billy]->[Bert]->|||
Popping Ramanujan
The stack now:
H->[Noel]->[Billy]->[Bert]->|||
Popping Noel
The stack now:
H->[Billy]->[Bert]->|||
Popping Billy
The stack now:
H->[Bert]->|||
Popping Bert
The stack now:
H->|||
Stack copy: //Done w/iterators
No Nonsense Roman Ramanujan Noel Billy Bert


INT STACK
---------------------------
The stack now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping:
---------------------------

Popping -8
The stack now:
H->[-7]->[-6]->[-5]->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping -7
The stack now:
H->[-6]->[-5]->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping -6
The stack now:
H->[-5]->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping -5
The stack now:
H->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping -4
The stack now:
H->[-3]->[-2]->[-1]->[0]->|||
Popping -3
The stack now:
H->[-2]->[-1]->[0]->|||
Popping -2
The stack now:
H->[-1]->[0]->|||
Popping -1
The stack now:
H->[0]->|||
Popping 0
The stack now:
H->|||


*************************************
QUEUE
*************************************
STRING QUEUE
---------------------------
Pushing Burt
Pushing Billy
Pushing Noel
Pushing Ramanujan
Pushing Roman
Pushing Nonsense
Pushing No
The end's size: 4
The beginning's size: 2
The queue is now:
H->[No]->[Nonsense]->[Roman]->[Ramanujan]->[Noel]->[Billy]->[Bert]->|||
Copying queue...
Popping:
---------------------------

Popping Bert
The queue is now:
H->[No]->[Nonsense]->[Roman]->[Ramanujan]->[Noel]->[Billy]->|||
Popping Billy
The queue is now:
H->[No]->[Nonsense]->[Roman]->[Ramanujan]->[Noel]->|||
Popping Noel
The queue is now:
H->[No]->[Nonsense]->[Roman]->[Ramanujan]->|||
Popping Ramanujan
The queue is now:
H->[No]->[Nonsense]->[Roman]->|||
Popping Roman
The queue is now:
H->[No]->[Nonsense]->|||
Popping Nonsense
The queue is now:
H->[No]->|||
Popping No
The queue is now:
H->|||
Queue copy:
No Nonsense Roman Ramanujan Noel Billy Bert


INT QUEUE
---------------------------
The queue now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->[-3]->[-2]->[-1]->[0]->|||
Popping:
---------------------------

Popping 0
The queue is now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->[-3]->[-2]->[-1]->|||
Popping -1
The queue is now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->[-3]->[-2]->|||
Popping -2
The queue is now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->[-3]->|||
Popping -3
The queue is now:
H->[-8]->[-7]->[-6]->[-5]->[-4]->|||
Popping -4
The queue is now:
H->[-8]->[-7]->[-6]->[-5]->|||
Popping -5
The queue is now:
H->[-8]->[-7]->[-6]->|||
Popping -6
The queue is now:
H->[-8]->[-7]->|||
Popping -7
The queue is now:
H->[-8]->|||
Popping -8
The queue is now:
H->|||

C:\Users\Manth\source\repos\Stack and Queue\Debug\Stack and Queue.exe (process 17008) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// popping an empty queue:
//---------------------------------------------------------------------
Assertion failed: head != nullptr && deleteThis != nullptr, file C:\Users\Manth\source\repos\Stack and Queue\Stack and Queue\Node.h, line 186
*/
#endif
