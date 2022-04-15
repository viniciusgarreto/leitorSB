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

#ifndef exception_table_h
#define exception_table_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

/**
* @file ExceptionTable.h
* @brief define uma tabela de exceções
*/
class ExceptionTable {
  public:
    ExceptionTable(FILE* fp);
    ///@{ 
    /** Informações sobre Exceções*/
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
    ///@}

    /// print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

#endif
