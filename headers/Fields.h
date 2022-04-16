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

#ifndef fields_h
#define fields_h

class Fields;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Field.h"

/**
* @file Fields.h
* @brief Dispões todos os Fields em um vetor de FIelds
*/
class Fields {
  public:
    Fields(FILE* fp, ConstantPool& cp);
    ~Fields();
    
    /// print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /// vetor de fields
    std::vector<Field*> fields;
    void ReadFieldsFromFile(FILE* fp, ConstantPool& cp);
    void AddField(Field* field);
    /// cotador de fields
    u2 fields_count;
};

#endif
