
#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run of all suites:
//---------------------------------------------------------------------
Adding to List:
Printing List:
H->[Taylor]->[Tina]->[boing]->[cat]->[Jacob]->[John]->|||
Copying List

Searching list and deleting cat....
Printing List:
H->[Taylor]->[Tina]->[boing]->[Jacob]->[John]->|||
Searching list and deleting Taylor....
Printing List:
H->[Tina]->[boing]->[Jacob]->[John]->|||
Searching list and deleting John....
Printing List:
H->[Tina]->[boing]->[Jacob]->|||
Inserting monster after boing....
Inserting fraud after Tina....
Inserting bingo after Jacob....
Printing List:
H->[Tina]->[fraud]->[boing]->[monster]->[Jacob]->[bingo]->|||
Inserting Taylor before monster....
Taylor's length: 6
Printing List:
H->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||
Inserting boing before Tina....
Printing List:
H->[boing]->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||
The First node: boing
Printing copy of original before changes:
H->[Taylor]->[Tina]->[boing]->[cat]->[Jacob]->[John]->|||Printing List Copy:
H->[Taylor]->[Tina]->[boing]->[cat]->[Jacob]->[John]->|||
P = L
H->[boing]->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||
H->[boing]->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||
After inserthead cat:
H->[cat]->[boing]->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||
H->[boing]->[Tina]->[fraud]->[boing]->[Taylor]->[monster]->[Jacob]->[bingo]->|||

Printing List Backward:
[bingo]<-[Jacob]<-[monster]<-[Taylor]<-[boing]<-[fraud]<-[Tina]<-[boing]<-[cat]<-
H->{5}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->5->{24}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->5->24->{78}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->5->24->78->{58}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: B
: 22
H->5->24->78->{22}->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: P
H->5->24->{78}->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: P
H->5->{24}->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: P
H->{5}->24->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: P
H->{5}->24->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: B
: 22
H->{22}->5->24->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{5}->24->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{24}->78->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{78}->22->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{22}->58->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{58}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{0}->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{34}->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->34->{67}->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{34}->67->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->34->{67}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: A
: 55
H->34->67->{55}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{34}->67->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{67}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{62}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: B
: 2
H->{2}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->2->{64}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: H
H->{2}->64->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{64}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: A
: 5
H->{5}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: E
Adding to List:
Printing List:
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||
Copying List

Searching list and deleting 90....
Printing List:
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||
Searching list and deleting 0....
Printing List:
H->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->|||
Searching list and deleting 40....
Printing List:
H->[10]->[20]->[30]->[50]->[60]->[70]->[80]->|||
The First node: 10
Printing copy of original before changes:
H->[0]->[10]->[20]->[30]->[40]->[50]->[60]->[70]->[80]->[90]->|||
Inserting sorted 45 in List Copy
Printing List Copy:
H->[0]->[10]->[20]->[30]->[40]->[45]->[50]->[60]->[70]->[80]->[90]->|||
Inserting sorted 100 in List Copy
Printing List Copy:
H->[0]->[10]->[20]->[30]->[40]->[45]->[50]->[60]->[70]->[80]->[90]->[100]->|||
Inserting sorted -1 in List Copy
Printing List Copy:
H->[-1]->[0]->[10]->[20]->[30]->[40]->[45]->[50]->[60]->[70]->[80]->[90]->[100]->|||
P = L
H->[10]->[20]->[30]->[50]->[60]->[70]->[80]->|||
H->[10]->[20]->[30]->[50]->[60]->[70]->[80]->|||
After insert 10:
H->[10]->[10]->[20]->[30]->[50]->[60]->[70]->[80]->|||
H->[10]->[20]->[30]->[50]->[60]->[70]->[80]->|||

Printing List Backward:
[80]<-[70]<-[60]<-[50]<-[30]<-[20]<-[10]<-[10]<-
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
The First node: 80
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
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->|||
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->|||
After insert 10:
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->[10]->|||
H->[80]->[70]->[60]->[50]->[30]->[20]->[10]->|||

Printing List Backward:
[10]<-[10]<-[20]<-[30]<-[50]<-[60]<-[70]<-[80]<-
H->{81}->61->45->27->5->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{91}->81->61->45->27->5->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{95}->91->81->61->45->27->5->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->95->91->81->61->45->{42}->27->5->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: I
: -1
H->95->91->81->61->45->42->27->5->{-1}->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: I
: 105
H->{105}->95->91->81->61->45->42->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->105->95->91->81->61->45->42->27->{27}->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: S
: 105
H->{105}->95->91->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: S
: -1
H->105->95->91->81->61->45->42->27->27->5->{-1}->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: S
: 81
H->105->95->91->{81}->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: P
H->105->95->{91}->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd:
P
H->105->{95}->91->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: H
H->{105}->95->91->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->105->{95}->91->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->105->95->{91}->81->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: N
H->105->95->91->{81}->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{105}->95->91->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{95}->91->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{91}->61->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{61}->45->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{45}->42->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{42}->27->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{27}->27->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{27}->5->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd:
D
H->{5}->-1->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{-1}->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{36}->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->{91}->36->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: R
H->91->36->{4}->|||
[R]andom [I]nsert [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: E

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 36292) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
#endif