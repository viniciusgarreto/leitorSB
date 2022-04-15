#ifndef instructions_h
#define instructions_h

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
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
    // ostream& print(ostream& output = cout) const;
    ostream& print(ostream& output, u1* code, ConstantPool& cp) const;

    string name;
    int opcode;
    int argnum;
    int opnum;
    int instruct_pc;

  private:
    static Instruction** instruc;
    static bool isBuilt;
    static int EnumCheck;
};
#endif
