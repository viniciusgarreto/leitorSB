#ifndef instructions_h
#define instructions_h

#include "definitions.h"
#include <stdio.h>

using namespace std;

/*
Classe de Instruções

define a estrutura de uma instrução.
*/
class Instruction {
  public:
    Instruction(string name, int opcode, int argnum, int opnum);
    ~Instruction();
    static void setInstructions();
    static Instruction& getInstruction(int opcode);

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const Instruction& cf);

  private:
    static Instruction** instruc;
    static bool isBuilt;
    static int EnumCheck;
    string name;
    int opcode;
    int argnum;
    int opnum;
    int instruct_pc;
};
#endif
