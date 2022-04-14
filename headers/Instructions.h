#ifndef instructions_h
#define instructions_h

#include "definitions.h"
#include <stdio.h>

using namespace std;

class Instruction {
  public:
    Instruction(string name, int opcode, int argnum, int opnum);
    ~Instruction();
    void setInstructions();
    static Instruction& getInstruction(int opcode);

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const Instruction& cf);

  private:
    static Instruction** instruc;
    string name;
    int opcode;
    int argnum;
    int opnum;
    int instruct_pc;
    int EnumCheck = 200;
};
#endif
