#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run of node_test.h suite:
//---------------------------------------------------------------------
Adding to List:
H->[0]->|||
H->[10]->[0]->|||
H->[20]->[10]->[0]->|||
H->[30]->[20]->[10]->[0]->|||
H->[40]->[30]->[20]->[10]->[0]->|||
H->[50]->[40]->[30]->[20]->[10]->[0]->|||
H->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
H->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
H->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||

Printing List:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Copying List

Searching list and deleting 90....
Printing List:
H->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Searching list and deleting 0....
Printing List:
H->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->|||
Searching list and deleting 40....
Printing List:
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->|||Inserting 999 after 50....
Inserting 999 before 80.... //NOT in original
Printing List:
H->[999]->[80]->[70]->[60]->[50]->[999]->[30]->[20]->[10]->|||
Inserting 999 before 10.... 
Printing List:
H->[999]->[80]->[70]->[60]->[50]->[999]->[30]->[20]->[999]->[10]->|||
The last node: [10]->
Printing copy of original before changes:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Where 45 goes in List Copy: [40]->
Where -1 goes in List Copy: [0]->
Inserting sorted 45 in List Copy
Printing List Copy:
H->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->|||
Inserting sorted 100 in List Copy
Printing List Copy:
H->[100]->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->|||
Inserting sorted -1 in List Copy
Printing List Copy:
H->[100]->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->[-1]->|||
Clearing List...

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 48812) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// normal run of list_test suite:
//---------------------------------------------------------------------
Adding to List:
Printing List:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Copying List

Searching list and deleting 90....
Printing List:
H->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Searching list and deleting 0....
Printing List:
H->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->|||
Searching list and deleting 40....
Printing List:
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->|||
Inserting 888 after 80....
Inserting 888 after 50....
Inserting 888 after 10....
Inserting 999 before 80....
Printing List:
H->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[10]->[888]->|||
Inserting 999 before 10....
Printing List:
H->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[999]->[10]->[888]->|||
The last node: [888]
Printing copy of original before changes:
H->[90]->[80]->[70]->[60]->[50]->[40]->[30]->[20]->[10]->[0]->|||
Inserting sorted 45 in List Copy
Printing List Copy:
H->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->|||
Inserting sorted 100 in List Copy
Printing List Copy:
H->[100]->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->|||
Inserting sorted -1 in List Copy
Printing List Copy:
H->[100]->[90]->[80]->[70]->[60]->[50]->[45]->[40]->[30]->[20]->[10]->[0]->[-1]->|||
P = L
H->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[999]->[10]->[888]->|||
H->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[999]->[10]->[888]->|||
After inserthead 10:
H->[10]->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[999]->[10]->[888]->|||
H->[999]->[80]->[888]->[70]->[60]->[50]->[888]->[30]->[20]->[999]->[10]->[888]->|||
//PRINT LIST BACKWARD
[888]<-[10]<-[999]<-[20]<-[30]<-[888]<-[50]<-[60]<-[70]<-[888]<-[80]<-[999]<-[10]<-

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 21348) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


//---------------------------------------------------------------------
// normal run of cursor class sans search
//---------------------------------------------------------------------
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->{[0]}->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[0]->{[34]}->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[0]->[34]->{[67]}->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[0]->[34]->[67]->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[0]->[34]->[67]->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[0]->[34]->[67]->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->[69]->[0]->[34]->{[67]}->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->[69]->[0]->{[34]}->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->[69]->{[0]}->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[69]->{[24]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[69]->[24]->{[78]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[69]->[24]->[78]->{[58]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: a
: 77
H->[69]->[24]->[78]->[58]->{[77]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->[69]->[24]->[78]->[58]->[77]->{[0]}->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: b
: 12
H->[69]->[24]->[78]->[58]->[77]->{[12]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[69]}->[24]->[78]->[58]->[77]->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[24]}->[78]->[58]->[77]->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[78]}->[58]->[77]->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[58]}->[77]->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[77]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[0]}->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[34]}->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[67]}->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: A
: 11
H->{[11]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{[62]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: B
: 44
H->{[44]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[44]->{[64]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[44]->[64]->{[5]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->[44]->[64]->[5]->{[45]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: h
H->{[44]}->[64]->[5]->[45]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: e

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 29948) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// normal run of cursor class search
//---------------------------------------------------------------------
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 69
H->{[69]}->[0]->[34]->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 41
H->[69]->[0]->[34]->[67]->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 1000
H->[69]->[0]->[34]->[67]->{[41]}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 34
H->[69]->[0]->{[34]}->[67]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: E

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 12488) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
#endif