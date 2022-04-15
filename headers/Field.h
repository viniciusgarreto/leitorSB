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

#ifndef field_h
#define field_h

class Field;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

/**
* @file Field.h
* @brief define a estrutura de um Field do Class File
*/
class Field {
  public:
  /// construtor
    Field(FILE* fp, ConstantPool& cp);
    ~Field();

    /// print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /// vetor de atributos
    std::vector<Attribute*> attributes;
    /// le os atributos do arquivo .class e os adiciona no vetor de atributos
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    /// adiciona atributo no vetor de atributos
    void AddAttribute(Attribute* attb);

    friend ostream &operator<<(std::ostream &, const Field &);

    /// flags de acesso que define características sobre o tipo da classe
    u2 access_flags;
    /// nome do campo
    u2 name;
    u2 descriptor;
    /// contagem de atributos no campo
    u2 attributes_count;
};

#endif
