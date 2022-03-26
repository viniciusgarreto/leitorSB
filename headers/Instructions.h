#ifndef instructions_h
#define instructions_h

#include "definitions.h"
#include <stdio.h>

using namespace std;

class Instruction {
   public:
    Instruction *setInstructions();

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const Instruction& cf);

   private:
    char name[40];
    u1 opcode;
    u1 argnum;
    u1 opnum;
    u1 instruct_pc;
    int EnumCheck = 200;
};
#endif