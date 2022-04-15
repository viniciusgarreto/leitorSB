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
* @file Interfaces.h
* @brief Classe Interfaces define uma interface do class file
*/

class Interfaces {
  public:
    /// Construtor
    Interfaces(FILE *fp);
    ~Interfaces();

    /// print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /**
    * @brief adiciona interface ao vetor de interfaces
    * @param interface - interfaxe a ser adicionada no vetor 
    */
    void AddInterface(u2 interface);
    /// Vetor de interfaces
    std::vector<u2> interfaces;
    /// Contador de interfaces
    u2 count;
};


#endif
