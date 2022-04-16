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

#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

/**
* @file Exceptions.h
* @brief define uma exceção
*/
class Exceptions {
  public:
    /// construtor
    Exceptions(FILE *fp);
    ~Exceptions();

    /**
     * @brief Transforma em String
     * @param cp - Constant Pool
     * @return Pedaço de Constant Pool em string
     */
    string ToString(ConstantPool& cp);

  private:
    ///Vetor de exceptions
    std::vector<u2> exceptions;
    ///Contador 
    u2 count; 
};


#endif
