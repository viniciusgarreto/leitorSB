/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

#ifndef instructions_h
#define instructions_h

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include <stdio.h>

using namespace std;

/**
* @file Instructions.h
* @brief Classe de Instruções define a estrutura de uma instrução.
*/
class Instruction {
  public:
    /// construtor
    Instruction(string name, int opcode, int argnum, int opnum);
    ~Instruction();
    
    /**
    * @brief cria todas as instruções e as atribui ao array de instruções (instruc[opcode])
    * @param opcode - referência da instrução desejada
    * @return Instruction - retorna a instrução procurada
    */
    static Instruction& getInstruction(int opcode);
    static void setInstructions();

    /// print methods
    ostream& print(ostream& output, u1* code, ConstantPool& cp) const;

    /// Nome da instrução
    string name;
    /// Codigo de instrução
    int opcode;
    /// Numero de argumento
    int argnum;
    /// Numero do operador
    int opnum;
    /// Contador de programas
    int instruct_pc;

  private:
    /// array alocada dinâmicamente, onde a gente guarda instâncias de Instruction
    static Instruction** instruc;
    /// booleano que diz se as instruções estão setadas no array ou não
    static bool isBuilt;
    /// número total de instruções possíveis, existem 200 tipos de instrução
    static int EnumCheck;
};
#endif
