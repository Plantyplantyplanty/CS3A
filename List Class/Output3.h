#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run test suite && menu
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



//Blank lines inserted manually for clarity
H->{5}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->5->{24}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->5->24->{78}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->{0}->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->0->{34}->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->0->34->{67}->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->0->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->0->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->24->78->0->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->24->78->0->34->{67}->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->24->78->0->{34}->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->24->78->{0}->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd:
p
H->5->24->{78}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->{24}->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{5}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{5}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: S
: 78
H->5->24->{78}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 41
H->5->24->78->0->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 5
H->{5}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 12
H->{5}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: a
: 12
H->5->{12}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: s
: 12
H->5->{12}->24->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->{24}->78->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->24->{78}->0->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->24->78->{0}->34->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->24->78->0->{34}->67->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->24->78->0->34->{67}->41->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: n
H->5->12->24->78->0->34->67->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: a
: 14
H->5->12->24->78->0->34->67->41->{14}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: b
: 15
H->5->12->24->78->0->34->67->41->{15}->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->24->78->0->34->67->{41}->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->24->78->0->34->{67}->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->24->78->0->{34}->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->24->78->{0}->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->24->{78}->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->12->{24}->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->5->{12}->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{5}->12->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: p
H->{5}->12->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: b
: 44
H->{44}->5->12->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: h
H->{44}->5->12->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{5}->12->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: D
H->{12}->24->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{24}->78->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{78}->0->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{0}->34->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{34}->67->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{67}->41->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{41}->15->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{15}->14->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{14}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->{58}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: r
H->58->{62}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->{58}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: b
: 14
H->{14}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: d
H->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: a
: 14
H->{14}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch [P] Previous  [N] Next  [H]ome  [E]nd: e

C:\Users\Manth\source\repos\List Class\Debug\List Class.exe (process 3596) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/

#endif