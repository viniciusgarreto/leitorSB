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

#ifndef line_number_table_h
#define line_number_table_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

/**
* @file LineNumberTable.h
* @brief Define estrutura da tabela de numero de linhas do arquivo .class
*/
class LineNumberTable {
  public:
    LineNumberTable(FILE* fp);
    /// Inicio do contador de programa
    u2 start_pc;
    /// Numero da linha
    u2 line_number;

    /// print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

#endif
