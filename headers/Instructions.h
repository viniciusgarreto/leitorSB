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
    void setInstructions();

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const Instruction& cf);

  private:
    Instruction* instruc;
    string name;
    int opcode;
    int argnum;
    int opnum;
    int instruct_pc;
    int EnumCheck = 200;
};
#endif
