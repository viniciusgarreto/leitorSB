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

#ifndef attributes_h
#define attributes_h

class Attributes;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

/**
* @file Attributes.h
* @brief Contem a lista de todos os attributes 
*/

class Attributes {
  public:
    /// construtor
    Attributes(FILE* fp, ConstantPool& cp);
    ~Attributes();
    
    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /**
     * @brief lê os atributos do arquivo fonte e od lista em attributes usando AddAttribue
     * @param fp - referencia para o arquivo fonte
     * @param cp - constant pull
     * retorno vazio
     */
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    /**
     * @brief adiciona o atributo na lista (vector) attributes
     * @param attributes - atributo a ser adicionado. @see Attribute
     */
    void AddAttribute(Attribute* attributes);

    /// lista de atributos
    std::vector<Attribute*> attributes;
    /// numero de atributos que há (contagem)
    u2 attributes_count;
};

#endif
