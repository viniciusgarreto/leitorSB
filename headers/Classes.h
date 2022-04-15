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

#ifndef classes_h
#define classes_h

class Classes;

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

/**
* @file Classes.h
* @brief Toda entrada CONSTANT_Class_info da tabela de constant_pool que
* representa uma class ou interface C que nao eh um membro de pacote tem que ter exatamente
* uma entrada correspondente no array de classes.
*/

class Classes {
  public:
    Classes(FILE* fp);
    /// Se C é anonimo, o valor de inner_name_index deve ser zero, senão, o valor deve ser um index valido na tabela de constant_pool
    u2 inner_name;
    /// o valor deve ser um index valido na tabela de constant_pool
    u2 inner_class_info;
    ///Mascara de flags usadas para denotar permissões de acessos e propriedades da classe ou interface C
    u2 inner_class_access_flags;
    ///Se C é anonimo, o valor de outer_name_index deve ser zero, senão, o valor deve ser um index valido na tabela de constant_pool
    u2 outer_class_info;
    /// print methods
    void print(unsigned int indent = 0);
};

#endif
